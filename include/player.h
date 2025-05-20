/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:36:18 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/18 11:54:38 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"

/**
 * @brief Initializes the player structure from app state
 *
 * @param data App state
 *
 * @note There are no checks for empty data struct, so passing a NULL *will*
 *       segfault.
 */
void	init_player(t_data *data);

/**
 * @brief Move the player
 * Bases itself on the current control state and collision detection.
 *
 * @param player Player
 * @param map Map
 *
 * @see Comments in `player_move.c`, they give context for the collision
 *      detection system.
 */
void	move_player(t_player *player, char **map);

#endif
