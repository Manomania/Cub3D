/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mov_pproc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:11:40 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 16:12:06 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#ifdef EXTRA

/*
** Check if a position is valid (not a wall)
*/
bool	is_valid_position(char **map, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0 || !map[map_y] || !map[map_y][map_x])
		return (false);
	if (map[map_y][map_x] == '1')
		return (false);
	return (true);
}
#else

bool	is_valid_position(char **map, double x, double y)
{
	(void) map;
	(void) x;
	(void) y;
	return (true);
}
#endif
