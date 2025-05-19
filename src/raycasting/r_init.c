/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:46:54 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/19 16:49:35 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file is for initializing the ray structure
*/

#include "raycasting.h"

/*
** This function calculates the ray position and direction
*/
static void	calculate_ray_pos_dir(t_ray *ray, t_player *player, double camera_x)
{
	ray->ray_dir_x = player->dir_x + player->plane_x * camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * camera_x;
}

/*
** This function calculates which box of the map we're in
*/
static void	calculate_map_box(t_ray *ray, t_player *player)
{
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
}

/*
** Calculate delta distances
** These are the distances the ray has to travel to go from 1 x-side to the next
** x-side, or from 1 y-side to the next y-side
*/
static void	calculate_delta_dists(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void	init_ray(t_ray *ray, t_player *player, double camera_x)
{
	calculate_ray_pos_dir(ray, player, camera_x);
	calculate_map_box(ray, player);
	calculate_delta_dists(ray);
}
