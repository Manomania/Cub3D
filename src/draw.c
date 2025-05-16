/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:31:43 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/16 17:53:35 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "draw.h"
#include "texture.h"

void	draw_textured_line(t_data *data, t_ray *ray, int x)
{
	t_texture		*texture;
	double			wall_x;
	double			step;
	double			tex_pos;
	unsigned int	color;
	int				y;

	int tex_x, tex_y;
	// Determine which wall texture to use
	texture = get_wall_texture(data->textures, ray);
	// Calculate where exactly the wall was hit (wall_x)
	if (ray->side == 0)
		wall_x = data->player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = data->player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	// Calculate x coordinate on the texture
	tex_x = (int)(wall_x * (double)texture->width);
	// Flip texture x coordinate if needed to ensure correct orientation
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1
			&& ray->ray_dir_y < 0))
		tex_x = texture->width - tex_x - 1;
	// How much to increase the texture coordinate per screen pixel
	step = 1.0 * texture->height / ray->line_height;
	// Starting texture coordinate
	tex_pos = (ray->draw_start - data->win_height / 2 + ray->line_height / 2)
		* step;
	// Draw the pixels of the stripe
	for (y = ray->draw_start; y < ray->draw_end; y++)
	{
		// Calculate y coordinate on the texture
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		// Get color from the texture
		color = get_pixel_color(texture, tex_x, tex_y);
		// Make color darker for y-sides (to create a shadow effect)
		if (ray->side == 1)
			color = (color >> 1) & 8355711; // Darker color by bit shifting
		// TODO: Change that /\ for union type
		// Draw pixel to image buffer
		my_mlx_pixel_put(data->img, x, y, color);
	}
}

void	draw_ceiling(t_data *data, int x, int start_y, int ceil_color)
{
	int	y;

	y = -1;
	while (++y < start_y)
		my_mlx_pixel_put(data->img, x, y, ceil_color);
}

void	draw_floor(t_data *data, int x, int end_y, int floor_color)
{
	int	y;

	y = end_y;
	while (++y < data->win_height)
		my_mlx_pixel_put(data->img, x, y, floor_color);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->img + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
