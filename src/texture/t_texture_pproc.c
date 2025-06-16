/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_texture_pproc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:27:44 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 18:40:24 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

#ifdef BONUS

bool	load_bonus_textures(t_data *data, char *door_path)
{
	if (!door_path)
		return (true);
	data->textures.door.img = mlx_xpm_file_to_image(data->mlx, door_path,
			&data->textures.door.width, &data->textures.door.height);
	if (!data->textures.door.img)
		return (true);
	data->textures.door.addr = mlx_get_data_addr(data->textures.door.img,
			&data->textures.door.bits_per_pixel,
			&data->textures.door.line_length,
			&data->textures.door.endian);
	return (false);
}

t_texture	*get_wall_texture_bonus(t_data *data, t_textures *textures,
				t_ray *ray)
{
	int	map_x;
	int	map_y;

	if (ray->side == SIDE_EAST_WEST)
	{
		map_x = (int)ray->vertical_x;
		map_y = (int)ray->vertical_y;
		if (ray->ray_dir_x < 0)
			map_x += 1;
	}
	else
	{
		map_x = (int)ray->horizontal_x;
		map_y = (int)ray->horizontal_y;
		if (ray->ray_dir_y > 0)
			map_y += 1;
	}
	if (map_y >= 0 && map_y < data->map_height
		&& map_x >= 0 && map_x < data->map_width
		&& data->map[map_y] && map_x < (int)ft_strlen(data->map[map_y]))
	{
		if (data->map[map_y][map_x] == 'D')
			return (&textures->door);
	}
	return (NULL);
}
#else

bool	load_bonus_textures(t_data *data, char *door_path)
{
	(void) data;
	(void) door_path;
	return (false);
}

t_texture	*get_wall_texture_bonus(t_data *data, t_textures *textures,
				t_ray *ray)
{
	(void) ray;
	(void) data;
	(void) textures;
	return (NULL);
}
#endif
