/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:46:54 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/16 16:52:31 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_ray(t_ray *ray, t_player *player, double camera_x)
{
	// Calculate ray position and direction
	ray->ray_dir_x = player->dir_x + player->plane_x * camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * camera_x;
	// Which box of the map we're in
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	// Calculate delta distances
	// These are the distances the ray has to travel to go from 1 x-side to the next x-side,
	// or from 1 y-side to the next y-side
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
