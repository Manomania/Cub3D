/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:55:08 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 18:43:38 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d.h"

# ifdef BONUS
#  include "minimap_bonus.h"
#  include "mouse_bonus.h"

/**
 * @brief Loads bonus textures only
 * @param data App data
 * @param door_path Door path
 * @returns Whethre it failed or not
 */
bool	load_bonus_textures(t_data *data, char *door_path);
# endif

#endif
