/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:32:13 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/19 16:14:14 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "cub3d.h"

// *************************************************************************** #
//                            Function Prototypes                              #
// *************************************************************************** #

/**
 * @brief Apply darkness to color for y-sides (shadow effect)
 *
 * @param color The original color
 * @param side The side of the wall hit (0 for x, 1 for y)
 * @return unsigned int The adjusted color
 */
unsigned int	apply_shadow(unsigned int color, int side);

/**
 * @brief Calculate the x-coordinate on the texture
 *
 * @param wall_x The wall hit position
 * @param texture The wall texture
 * @param ray The ray information
 * @return int The x-coordinate on the texture
 */
int				calculate_texture_x(double wall_x, t_texture *texture,
					t_ray *ray);

/**
 * @brief Calculate where exactly the wall was hit
 *
 * @param data The game data structure
 * @param ray The ray information
 * @return double The exact hit position on the wall (0-1)
 */
double			calculate_wall_hit(t_data *data, t_ray *ray);

/**
 * @brief Draw a textured vertical line on the screen
 *
 * @param data App data
 * @param ray Ray pointing to where to draw
 * @param x X coorinate
 */
void			draw_textured_line(t_data *data, t_ray *ray, int x);

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
void			draw_ceiling(t_data *data, int x, int start_y, int ceil_color);

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
void			draw_floor(t_data *data, int x, int end_y, int floor_color);

/**
 * @brief Puts a pixel to a MLX image
 *
 * @param img MLX image
 * @param x Pixel X coordinate
 * @param y Pixel Y coordinate
 * @param color Pixel color
 *
 * @note Replacement for vanilla pixel put counterpart
 * @todo Change this to allow for uniontype color
 */
void			my_mlx_pixel_put(t_img *img, int x, int y, unsigned int color);

/**
 * @brief Renders a frame. Duh.
 *
 * @param data App data
 */
void			render_frame(t_data *data);

#endif
