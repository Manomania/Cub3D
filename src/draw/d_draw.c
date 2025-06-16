/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_draw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:31:43 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 17:43:28 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "draw.h"
#include "texture.h"

static void	draw_line_pixels(t_data *data, t_ray *ray, t_texture *texture,
		int x)
{
	double	step;
	double	tex_pos;
	t_color	color;
	int		y;
	int		tex_y;

	step = 1.0 * texture->height / ray->line_height;
	tex_pos = (ray->draw_start - data->win_height / 2 + ray->line_height / 2)
		* step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		color = get_pixel_color(texture, ray->tex_x, tex_y);
		color = apply_shadow(color, ray->side);
		my_mlx_pixel_put(&data->img, x, y, color);
		y++;
	}
}

void	draw_textured_line(t_data *data, t_ray *ray, int x)
{
	t_texture	*texture;
	double		wall_x;

	texture = get_wall_texture(data, &data->textures, ray);
	wall_x = calculate_wall_hit(data, ray);
	ray->tex_x = calculate_texture_x(wall_x, texture, ray);
	draw_line_pixels(data, ray, texture, x);
}

void	draw_ceiling(t_data *data, int x, int start_y, t_color ceil_color)
{
	int	y;

	y = -1;
	while (++y < start_y)
		my_mlx_pixel_put(&data->img, x, y, ceil_color);
}

void	draw_floor(t_data *data, int x, int end_y, t_color floor_color)
{
	int	y;

	y = end_y;
	while (++y < data->win_height)
		my_mlx_pixel_put(&data->img, x, y, floor_color);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, t_color color)
{
	char	*dst;

	if (!img || !img->addr)
		return ;
	if (x < 0 || y < 0 || x >= WIN_W || y >= WIN_H)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color.val;
}
