/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:22:49 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/16 19:03:42 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file should never see the prod.
*/

#include "cub3d.h"
#include "mlx.h"

/*
** Generate dummy textures for testing without loading files
** Creates different patterns for each direction
*/
int	generate_dummy_textures(t_data *data)
{
	const int		tex_width = 64;
	const int		tex_height = 64;
	unsigned int	*buffer;
	unsigned char	intensity;
	int				centerX;
	int				centerY;
	int				distance;

	int x, y;
	// Initialize north texture (red brick pattern)
	data->textures.north.img = mlx_new_image(data->mlx, tex_width, tex_height);
	if (!data->textures.north.img)
		return (0);
	data->textures.north.addr = mlx_get_data_addr(data->textures.north.img,
			&data->textures.north.bits_per_pixel,
			&data->textures.north.line_length, &data->textures.north.endian);
	data->textures.north.width = tex_width;
	data->textures.north.height = tex_height;
	buffer = (unsigned int *)data->textures.north.addr;
	for (y = 0; y < tex_height; y++)
	{
		for (x = 0; x < tex_width; x++)
		{
			// Create brick pattern - red with darker grout lines
			if ((x % 16 == 0) || (y % 16 == 0))
				buffer[y * tex_width + x] = 0x551111;
			// Dark red for grout lines
			else
				buffer[y * tex_width + x] = 0xFF2222; // Bright red for bricks
		}
	}
	// Initialize south texture (blue checkerboard pattern)
	data->textures.south.img = mlx_new_image(data->mlx, tex_width, tex_height);
	if (!data->textures.south.img)
		return (0);
	data->textures.south.addr = mlx_get_data_addr(data->textures.south.img,
			&data->textures.south.bits_per_pixel,
			&data->textures.south.line_length, &data->textures.south.endian);
	data->textures.south.width = tex_width;
	data->textures.south.height = tex_height;
	buffer = (unsigned int *)data->textures.south.addr;
	for (y = 0; y < tex_height; y++)
	{
		for (x = 0; x < tex_width; x++)
		{
			// Create checkerboard pattern in blue
			if ((x / 8 + y / 8) % 2 == 0)
				buffer[y * tex_width + x] = 0x2222FF; // Bright blue
			else
				buffer[y * tex_width + x] = 0x0000AA; // Dark blue
		}
	}
	// Initialize east texture (green gradient pattern)
	data->textures.east.img = mlx_new_image(data->mlx, tex_width, tex_height);
	if (!data->textures.east.img)
		return (0);
	data->textures.east.addr = mlx_get_data_addr(data->textures.east.img,
			&data->textures.east.bits_per_pixel,
			&data->textures.east.line_length, &data->textures.east.endian);
	data->textures.east.width = tex_width;
	data->textures.east.height = tex_height;
	buffer = (unsigned int *)data->textures.east.addr;
	for (y = 0; y < tex_height; y++)
	{
		for (x = 0; x < tex_width; x++)
		{
			// Create horizontal gradient in green
			intensity = (unsigned char)(255 * x / tex_width);
			buffer[y * tex_width + x] = 0x00FF00 + (intensity << 8);
			// Green gradient
			// Add small grid pattern
			if ((x % 8 == 0) || (y % 8 == 0))
				buffer[y * tex_width + x] = buffer[y * tex_width + x] / 2;
			// Darker grid lines
		}
	}
	// Initialize west texture (yellow/orange circular pattern)
	data->textures.west.img = mlx_new_image(data->mlx, tex_width, tex_height);
	if (!data->textures.west.img)
		return (0);
	data->textures.west.addr = mlx_get_data_addr(data->textures.west.img,
			&data->textures.west.bits_per_pixel,
			&data->textures.west.line_length, &data->textures.west.endian);
	data->textures.west.width = tex_width;
	data->textures.west.height = tex_height;
	buffer = (unsigned int *)data->textures.west.addr;
	for (y = 0; y < tex_height; y++)
	{
		for (x = 0; x < tex_width; x++)
		{
			// Create concentric circles in yellow/orange
			centerX = tex_width / 2;
			centerY = tex_height / 2;
			distance = (int)sqrt((x - centerX) * (x - centerX) + (y - centerY)
					* (y - centerY));
			if (distance % 8 < 4)
				buffer[y * tex_width + x] = 0xFFAA00; // Bright orange
			else
				buffer[y * tex_width + x] = 0xFFFF00; // Yellow
		}
	}
	return (1);
}

/*
** Generate a dummy map for testing without parsing a file
*/
int	generate_dummy_map(t_data *data)
{
	const char *dummy_map[] = {"111111111111111111111111",
								"100000000000000000000001",
								"100000000000000000000001",
								"100000111100000111100001",
								"100000100100000100100001",
								"100000111100000111100001",
								"100000000000000000000001",
								"100000000000000000000001",
								"100000000000000000000001",
								"100000000000000000000001",
								"100000111100000111100001",
								"100000100100000100100001",
								"100000111100000111100001",
								"100000000000000000000001",
								"100000000000N00000000001",
								// Player starts here facing North
								"100000000000000000000001",
								"111111111111111111111111",
								NULL};
	int i, map_height = 0;
	// Count map height
	while (dummy_map[map_height])
		map_height++;
	// Allocate memory for map
	data->map = (char **)malloc(sizeof(char *) * (map_height + 1));
	if (!data->map)
		return (0);
	// Copy map lines
	for (i = 0; i < map_height; i++)
		data->map[i] = ft_strdup(dummy_map[i]);
	// Null-terminate map array
	data->map[map_height] = NULL;
	// Set map dimensions
	data->map_height = map_height;
	data->map_width = ft_strlen(dummy_map[0]);
	// Set floor and ceiling colors
	data->floor_color = 0x555555; // Gray
	data->ceil_color = 0xAAAAAA;  // Light gray
	return (1);
}
