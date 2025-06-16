/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:55:08 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 19:14:25 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d.h"

# ifdef BONUS
#  include "minimap_bonus.h"
#  include "mouse_bonus.h"

/**
 * @brief Checks if a door can be passed at the moment
 * @param data App data
 * @param x X coordinate of the door
 * @param y Y coordinate of the door
 * @returns Boolean result
 */
bool	is_door_passable(t_data *data, int x, int y);

/**
 * @brief Loads bonus textures only
 * @param data App data
 * @param door_path Door path
 * @returns Whethre it failed or not
 */
bool	load_bonus_textures(t_data *data, char *door_path);

/**
 * @brief Toggles a door opened/closed
 * @param data App data
 * @param x X coordinate of the door
 * @param y Y coordinate of the door
 */
void	toggle_door(t_data *data, int x, int y);

/**
 * @brief Updates the door animation
 * @param data App data
 */
void	update_door_animations(t_data *data);
# endif

#endif
