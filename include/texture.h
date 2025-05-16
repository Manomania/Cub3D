/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:22:00 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/16 19:03:42 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "cub3d.h"

// *************************************************************************** #
//                            Function Prototypes                              #
// *************************************************************************** #

/**
 * @brief Get RGB color from image data at specific position
 *
 * @param texture Pointer to texture struct
 * @param x X coordinate
 * @param y Y coordinate
 * @return unsigned int Pixel color
 */
unsigned int	get_pixel_color(t_texture *texture, int x, int y);

/**
 * @brief Determine which texture to use based on wall orientation
 *
 * @param textures Pointer to textures struct
 * @param ray Pointer to ray
 * @return t_texture* Pointer to a newly initialized texture object
 */
t_texture		*get_wall_texture(t_textures *textures, t_ray *ray);

/**
 * @brief Load textures from XPM files
 *
 * @param textures Pointer to textures struct
 * @param mlx_ptr Pointer to MLX struct
 * @param north_path Path to northern texture
 * @param south_path Path to southern texture
 * @param east_path Path to eastern texture
 * @param west_path Path to western texture
 * @return bool Whether the function succeeded or not
 */
bool			load_textures(t_textures *textures, void *mlx_ptr,
					char *north_path, char *south_path, char *east_path,
					char *west_path);

#endif
