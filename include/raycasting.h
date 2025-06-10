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

// /**
//  * @brief Calculate the height of the line to draw on screen
//  *
//  * @param ray Ray
//  * @param screen_height Screen height, duh
//  */
// void	calculate_line_height(t_ray *ray, int screen_height);
//
// /**
//  * @brief Calculate the step direction and initial side distance
//  *
//  * @param ray Ray
//  * @param player Player
//  */
// void	calculate_step_and_side_dist(t_ray *ray, t_player *player);
//
// /**
//  * @brief Calculate the distance to the wall
//  *
//  * @param ray Ray
//  */
// void	calculate_wall_distance(t_ray *ray);
//
// /**
//  * @brief Cast a single ray for a given x coordinate on the screen
//  *
//  * @param data App data
//  * @param ray Ray
//  * @param x X coordinte
//  */
// void	cast_ray(t_data *data, t_ray *ray, int x);
//
// /**
//  * @brief Initialize a ray structure for a specific screen x coordinate
//  *
//  * @param ray Ray
//  * @param player Player
//  * @param camera_x Camera X position
//  */
// void	init_ray(t_ray *ray, t_player *player, double camera_x);
//
// /**
//  * @brief Perform DDA algorithm to find wall hit
//  *
//  * @param ray Ray
//  * @param map Map
//  */
// void	perform_dda(t_ray *ray, char **map);
//
// /**
//  * @brief Main raycasting function
//  * To be called in the main loop. Loops through each vertical stripe of the
//  * screen.
//  *
//  * @param data App data
//  */
void	grid_raycasting(t_data *data);

#endif
