/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:40:53 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/16 19:03:42 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

// *************************************************************************** #
//                            Function Prototypes                              #
// *************************************************************************** #

/*
** r_horizontal.c
*/

void	find_horizontal_intersection(t_data *data, t_ray *ray);

/*
** r_raycasting.c
*/

void	calculate_final_distance(t_data *data, t_ray *ray);

void	grid_raycasting(t_data *data);

/*
** r_utils.c
*/

void	init_ray(t_ray *ray, t_player *player, double camera_x);

void	calculate_line_height(t_ray *ray, int screen_height);

bool	is_valid_and_walkable(t_data *data, int x, int y);

/*
** r_vertical.c
*/

void	find_vertical_intersection(t_data *data, t_ray *ray);



#endif
