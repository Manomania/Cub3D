/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mov_pproc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:11:40 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 19:03:26 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

#ifdef EXTRA

/*
** Check if a position is valid (not a wall)
*/
bool	is_valid_position(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0 || !data->map[map_y] || !data->map[map_y][map_x])
		return (false);
	if (data->map[map_y][map_x] == '1')
		return (false);
	if (data->map[map_y][map_x] == 'D')
		return (is_door_passable(data, map_x, map_y));
	return (true);
}
#else

bool	is_valid_position(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0 || !data->map[map_y] || !data->map[map_y][map_x])
		return (false);
	if (data->map[map_y][map_x] == '1')
		return (false);
	if (data->map[map_y][map_x] == 'D')
		return (false);
	return (true);
}
#endif
