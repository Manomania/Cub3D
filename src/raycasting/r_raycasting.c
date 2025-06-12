/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_raycasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_username <your_email@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:48:42 by maximart          #+#    #+#             */
/*   Updated: 2025/06/04 15:10:24 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "draw.h"
#include "raycasting.h"
#include <float.h>

static void	cast_grid_ray(t_data *data, t_ray *ray, int x);
static void	find_horizontal_intersection(t_data *data, t_ray *ray);
static void	find_vertical_intersection(t_data *data, t_ray *ray);
static void	calculate_final_distance(t_data *data, t_ray *ray);
static void	calculate_line_height(t_ray *ray, int screen_height);
static void	init_ray(t_ray *ray, t_player *player, double camera_x);
static void	calculate_horizontal_steps(double angle, double *step_x,
				double *step_y);
static void	calculate_vertical_steps(double angle, double *step_x,
				double *step_y);
static void	set_initial_horizontal_pos(t_data *data, t_ray *ray,
				double angle);
static void	set_initial_vertical_pos(t_data *data, t_ray *ray,
				double angle);
static void	step_until_horizontal_wall(t_data *data, t_ray *ray,
				double step_x, double step_y);
static void	step_until_vertical_wall(t_data *data, t_ray *ray,
				double step_x, double step_y);

void	grid_raycasting(t_data *data)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < data->win_width)
	{
		cast_grid_ray(data, &ray, x);
		draw_ceiling(data, x, ray.draw_start, data->ceil_color);
		draw_textured_line(data, &ray, x);
		draw_floor(data, x, ray.draw_end, data->floor_color);
		x++;
	}
}

static void	cast_grid_ray(t_data *data, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)data->win_width - 1;
	init_ray(ray, &data->player, camera_x);
	find_horizontal_intersection(data, ray);
	find_vertical_intersection(data, ray);
	calculate_final_distance(data, ray);
	calculate_line_height(ray, data->win_height);
}

static void	init_ray(t_ray *ray, t_player *player, double camera_x)
{
	ray->ray_dir_x = player->dir_x - player->plane_x * camera_x;
	ray->ray_dir_y = player->dir_y - player->plane_y * camera_x;
	ray->hit = 0;
}

static void	find_horizontal_intersection(t_data *data, t_ray *ray)
{
	double	step_x;
	double	step_y;
	double	angle;

	angle = atan2(ray->ray_dir_y, ray->ray_dir_x);
	if (fabs(sin(angle)) < 0.000001)
	{
		ray->horizontal_x = DBL_MAX;
		ray->horizontal_dist = DBL_MAX;
		return ;
	}
	calculate_horizontal_steps(angle, &step_x, &step_y);
	set_initial_horizontal_pos(data, ray, angle);
	step_until_horizontal_wall(data, ray, step_x, step_y);
}

static void	calculate_horizontal_steps(double angle, double *step_x,
		double *step_y)
{
	if (sin(angle) > 0.0)
	{
		*step_y = -1.0;
		*step_x = 1.0 / tan(angle);
	}
	else
	{
		*step_y = 1.0;
		*step_x = -1.0 / tan(angle);
	}
}

static void	set_initial_horizontal_pos(t_data *data, t_ray *ray, double angle)
{
	double	player_x;
	double	player_y;

	player_x = data->player.pos_x;
	player_y = data->player.pos_y;
	if (sin(angle) > 0.0)
		ray->horizontal_y = floor(player_y) - 0.000001;
	else
		ray->horizontal_y = floor(player_y) + 1.0;
	ray->horizontal_x = player_x + (player_y - ray->horizontal_y) / tan(angle);
}

static bool	is_valid_and_walkable(t_data *data, int x, int y)
{
	if (y < 0 || y >= data->map_height)
		return (false);
	if (x < 0 || x >= data->map_width)
		return (false);
	if (!data->map[y])
		return (false);
	if (x >= (int)ft_strlen(data->map[y]))
		return (false);
	return (data->map[y][x] != '1');
}

static void	step_until_horizontal_wall(t_data *data, t_ray *ray,
		double step_x, double step_y)
{
	int	map_x;
	int	map_y;
	int	safety;

	safety = 0;
	map_x = (int)floor(ray->horizontal_x);
	map_y = (int)floor(ray->horizontal_y);
	while (safety < 1000 && is_valid_and_walkable(data, map_x, map_y))
	{
		ray->horizontal_x += step_x;
		ray->horizontal_y += step_y;
		map_x = (int)floor(ray->horizontal_x);
		map_y = (int)floor(ray->horizontal_y);
		safety++;
	}
}

static void	find_vertical_intersection(t_data *data, t_ray *ray)
{
	double	step_x;
	double	step_y;
	double	angle;

	angle = atan2(ray->ray_dir_y, ray->ray_dir_x);
	if (fabs(cos(angle)) < 0.000001)
	{
		ray->vertical_y = DBL_MAX;
		ray->vertical_dist = DBL_MAX;
		return ;
	}
	calculate_vertical_steps(angle, &step_x, &step_y);
	set_initial_vertical_pos(data, ray, angle);
	step_until_vertical_wall(data, ray, step_x, step_y);
}

static void	calculate_vertical_steps(double angle, double *step_x,
		double *step_y)
{
	if (cos(angle) < 0.0)
	{
		*step_x = -1.0;
		*step_y = 1.0 * tan(angle);
	}
	else
	{
		*step_x = 1.0;
		*step_y = -1.0 * tan(angle);
	}
}

static void	set_initial_vertical_pos(t_data *data, t_ray *ray, double angle)
{
	double	player_x;
	double	player_y;

	player_x = data->player.pos_x;
	player_y = data->player.pos_y;
	if (cos(angle) < 0.0)
		ray->vertical_x = floor(player_x) - 0.000001;
	else
		ray->vertical_x = floor(player_x) + 1.0;
	ray->vertical_y = player_y + (player_x - ray->vertical_x) * tan(angle);
}

static void	step_until_vertical_wall(t_data *data, t_ray *ray,
		double step_x, double step_y)
{
	int	map_x;
	int	map_y;
	int	safety;

	safety = 0;
	map_x = (int)floor(ray->vertical_x);
	map_y = (int)floor(ray->vertical_y);
	while (safety < 1000 && is_valid_and_walkable(data, map_x, map_y))
	{
		ray->vertical_x += step_x;
		ray->vertical_y += step_y;
		map_x = (int)floor(ray->vertical_x);
		map_y = (int)floor(ray->vertical_y);
		safety++;
	}
}

static void	calculate_final_distance(t_data *data, t_ray *ray)
{
	double	player_angle;
	double	ray_angle;
	double	correction;
	double	player_x;
	double	player_y;
	double	dx_h;
	double	dy_h;
	double	dx_v;
	double	dy_v;

	ray_angle = atan2(ray->ray_dir_y, ray->ray_dir_x);
	player_x = data->player.pos_x;
	player_y = data->player.pos_y;
	if (ray->horizontal_x != DBL_MAX)
	{
		dx_h = ray->horizontal_x - player_x;
		dy_h = ray->horizontal_y - player_y;
		ray->horizontal_dist = sqrt(dx_h * dx_h + dy_h * dy_h);
	}
	else
		ray->horizontal_dist = DBL_MAX;
	if (ray->vertical_y != DBL_MAX)
	{
		dx_v = ray->vertical_x - player_x;
		dy_v = ray->vertical_y - player_y;
		ray->vertical_dist = sqrt(dx_v * dx_v + dy_v * dy_v);
	}
	else
		ray->vertical_dist = DBL_MAX;
	if (ray->vertical_dist < ray->horizontal_dist)
	{
		ray->perp_wall_dist = ray->vertical_dist;
		ray->side = SIDE_EAST_WEST;
	}
	else
	{
		ray->perp_wall_dist = ray->horizontal_dist;
		ray->side = SIDE_NORTH_SHOUTH;
	}
	player_angle = atan2(data->player.dir_y, data->player.dir_x);
	correction = cos(ray_angle - player_angle);
	ray->perp_wall_dist *= correction;
}

static void	calculate_line_height(t_ray *ray, int screen_height)
{
	ray->line_height = (int)(screen_height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + screen_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + screen_height / 2;
	if (ray->draw_end >= screen_height)
		ray->draw_end = screen_height - 1;
}
