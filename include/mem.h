/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:57:52 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/19 16:01:08 by elagouch         ###   ########.fr       */
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
void	*free_data(t_data *data);

/**
 * @brief Frees the map
 *
 * @param map Cub3d map
 */
void	free_map(char **map);

#endif
