/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:44:59 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/16 19:03:42 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "draw.h"
#include "raycasting.h"

void	cast_ray(t_data *data, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)data->win_width - 1;
	init_ray(ray, &data->player, camera_x);
	calculate_step_and_side_dist(ray, &data->player);
	perform_dda(ray, data->map);
	calculate_wall_distance(ray);
	calculate_line_height(ray, data->win_height);
}

void	raycasting(t_data *data)
{
	t_ray	ray;
	int		x;

	x = -1;
	while (++x < data->win_width)
	{
		cast_ray(data, &ray, x);
		draw_ceiling(data, x, ray.draw_start, data->ceil_color);
		draw_textured_line(data, &ray, x);
		draw_floor(data, x, ray.draw_end, data->floor_color);
	}
}
