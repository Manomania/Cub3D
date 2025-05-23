/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:57:52 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/21 16:35:16 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file is named `mem.h` because there already is a `memory.h` in the\
** standard lib.
*/

#ifndef MEM_H
# define MEM_H

# include "cub3d.h"

// *************************************************************************** #
//                            Function Prototypes                              #
// *************************************************************************** #

/**
 * @brief Final clearing function
 *
 * @param data Data to be cleared
 * @return void* New value for parameter
 */
void	*free_ressource(t_data *data);

/**
 * @brief Frees the map
 *
 * @param data Cub3d map
 */
void	free_map(t_data *data);

/**
 * @brief Frees the map copy
 *
 * @param map_copy Cub3d map copy
 * @param height Cub3d map height
 */
void	free_map_copy(char **map_copy, int height);

/**
 * @brief init the map
 *
 * @param data Cub3d map
 */
bool	init_map_array(t_data *data);

#endif
