/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:40:53 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/16 17:50:43 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

// *************************************************************************** #
//                            Function Prototypes                              #
// *************************************************************************** #

/**
 * @brief Calculate the height of the line to draw on screen
 *
 * @param ray Ray
 * @param screen_height Screen height, duh
 */
void	calculate_line_height(t_ray *ray, int screen_height);

/**
 * @brief Calculate the step direction and initial side distance
 *
 * @param ray Ray
 * @param player Player
 */
void	calculate_step_and_side_dist(t_ray *ray, t_player *player);

/**
 * @brief Calculate the distance to the wall
 *
 * @param ray Ray
 */
void	calculate_wall_distance(t_ray *ray);

/**
 * @brief Cast a single ray for a given x coordinate on the screen
 *
 * @param ray Ray
 * @param player Player
 * @param map Map
 * @param x X coordinte
 * @param screen_width Screen width
 * @param screen_height Screen height
 */
void	cast_ray(t_ray *ray, t_player *player, char **map, int x,
			int screen_width, int screen_height);

/**
 * @brief Initialize a ray structure for a specific screen x coordinate
 *
 * @param ray Ray
 * @param player Player
 * @param camera_x Camera X position
 */
void	init_ray(t_ray *ray, t_player *player, double camera_x);

/**
 * @brief Perform DDA algorithm to find wall hit
 *
 * @param ray Ray
 * @param map Map
 */
void	perform_dda(t_ray *ray, char **map);

/**
 * @brief Main raycasting function
 * To be called in the main loop.
 *
 * @param data App data
 */
void	raycasting(t_data *data);

#endif
