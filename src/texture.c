/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:20:52 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/16 17:54:31 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include "texture.h"

bool	load_textures(t_textures *textures, void *mlx_ptr, char *north_path,
		char *south_path, char *east_path, char *west_path)
{
	// Load north texture
	textures->north.img = mlx_xpm_file_to_image(mlx_ptr, north_path,
			&textures->north.width, &textures->north.height);
	if (!textures->north.img)
		return (false);
	textures->north.addr = mlx_get_data_addr(textures->north.img,
			&textures->north.bits_per_pixel, &textures->north.line_length,
			&textures->north.endian);
	// Load south texture
	textures->south.img = mlx_xpm_file_to_image(mlx_ptr, south_path,
			&textures->south.width, &textures->south.height);
	if (!textures->south.img)
		return (false);
	textures->south.addr = mlx_get_data_addr(textures->south.img,
			&textures->south.bits_per_pixel, &textures->south.line_length,
			&textures->south.endian);
	// Load east texture
	textures->east.img = mlx_xpm_file_to_image(mlx_ptr, east_path,
			&textures->east.width, &textures->east.height);
	if (!textures->east.img)
		return (false);
	textures->east.addr = mlx_get_data_addr(textures->east.img,
			&textures->east.bits_per_pixel, &textures->east.line_length,
			&textures->east.endian);
	// Load west texture
	textures->west.img = mlx_xpm_file_to_image(mlx_ptr, west_path,
			&textures->west.width, &textures->west.height);
	if (!textures->west.img)
		return (false);
	textures->west.addr = mlx_get_data_addr(textures->west.img,
			&textures->west.bits_per_pixel, &textures->west.line_length,
			&textures->west.endian);
	return (true);
}

unsigned int	get_pixel_color(t_texture *texture, int x, int y)
{
	char	*pixel;

	pixel = texture->addr + (y * texture->line_length + x
			* (texture->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

t_texture	*get_wall_texture(t_textures *textures, t_ray *ray)
{
	// If ray hit a north or south facing wall
	if (ray->side == 1)
	{
		// North-facing wall (ray direction is negative y)
		if (ray->ray_dir_y < 0)
			return (&textures->north);
		// South-facing wall (ray direction is positive y)
		else
			return (&textures->south);
	}
	// If ray hit an east or west facing wall
	else
	{
		// West-facing wall (ray direction is negative x)
		if (ray->ray_dir_x < 0)
			return (&textures->west);
		// East-facing wall (ray direction is positive x)
		else
			return (&textures->east);
	}
}
