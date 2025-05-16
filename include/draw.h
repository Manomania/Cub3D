/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:32:13 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/16 17:53:09 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "cub3d.h"
# include "mlx_int.h"

// *************************************************************************** #
//                            Function Prototypes                              #
// *************************************************************************** #

/**
 * @brief Draw a textured vertical line on the screen
 *
 * @param data App data
 * @param ray Ray pointing to where to draw
 * @param x X coorinate
 */
void	draw_textured_line(t_data *data, t_ray *ray, int x);

/**
 * @brief Draw ceiling with solid color
 *
 * @param data App data
 * @param x X coordinate
 * @param start_y Start Y coordinate
 * @param ceil_color Ceiling color
 *
 * @todo Change this to allow for uniontype color
 */
void	draw_ceiling(t_data *data, int x, int start_y, int ceil_color);

/**
 * @brief Draw floor with solid color
 *
 * @param data App data
 * @param x X coordinate
 * @param end_y End Y coordinate
 * @param floor_color Floor color
 *
 * @todo Change this to allow for uniontype color
 */
void	draw_floor(t_data *data, int x, int end_y, int floor_color);

/**
 * @brief Puts a pixel to a MLX image
 *
 * @param data App data
 * @param x Pixel X coordinate
 * @param y Pixel Y coordinate
 * @param color Pixel color
 *
 * @note Replacement for vanilla pixel put counterpart
 * @todo Change this to allow for uniontype color
 */
void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);

#endif
