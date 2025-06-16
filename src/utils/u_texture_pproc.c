/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_texture_pproc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:28:48 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 18:41:55 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "texture.h"
#include "utils.h"

#ifdef BONUS

bool	load_game_textures_bonus(t_data *data)
{
	char	*door_resolved_path;
	bool	door_success;

	if (data->texture_door)
	{
		door_resolved_path = resolve_path(data->map_file_path, data->texture_door);
		if (!door_resolved_path)
		{
			ft_printf(RED "Error\nFailed to resolve door texture path\n" RESET);
			return (true);
		}
		
		door_success = load_bonus_textures(data, door_resolved_path);
		free(door_resolved_path);
		
		if (door_success)
		{
			ft_printf(RED "Error\nFailed to load door texture\n" RESET);
			return (true);
		}
	}

	return (false);
}
#else

bool	load_game_textures_bonus(t_data *data)
{
	(void) data;
	return (false);
}
#endif
