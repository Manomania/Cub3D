/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:44:59 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/16 17:53:09 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "draw.h"
#include "raycasting.h"

void	cast_ray(t_ray *ray, t_player *player, char **map, int x,
		int screen_width, int screen_height)
{
	double	camera_x;

	camera_x = 2 * x / (double)screen_width - 1;
	init_ray(ray, player, camera_x);
	calculate_step_and_side_dist(ray, player);
	perform_dda(ray, map);
	calculate_wall_distance(ray);
	calculate_line_height(ray, screen_height);
}

void	raycasting(t_data *data)
{
	t_ray	ray;
	int		x;

	// Loop through each vertical stripe of the screen
	x = -1;
	while (++x < data->win_width)
	{
		// Cast ray
		cast_ray(&ray, data->player, data->map, x, data->win_width,
			data->win_height);
		// Draw ceiling
		draw_ceiling(data, x, ray.draw_start, data->ceil_color);
		// Draw textured wall
		draw_textured_line(data, &ray, x);
		// Draw floor
		draw_floor(data, x, ray.draw_end, data->floor_color);
	}
}
