/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:07:20 by maximart          #+#    #+#             */
/*   Updated: 2025/05/23 10:07:20 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**create_map_copy(t_data *data)
{
	char	**map_copy;
	int		i;

	map_copy = ft_calloc(data->map_height + 1, sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < data->map_height && data->map[i])
	{
		map_copy[i] = ft_strdup(data->map[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	return (map_copy);
}

static bool	is_valid_position(int x, int y, t_data *data)
{
	if (y < 0 || y >= data->map_height)
		return (false);
	if (x < 0 || x >= (int)ft_strlen(data->map[y]))
		return (false);
	return (true);
}

static bool	is_boundary_position(int x, int y, t_data *data)
{
	if (y == 0 || y == data->map_height - 1)
		return (true);
	if (x == 0 || x >= (int)ft_strlen(data->map[y]) - 1)
		return (true);
	return (false);
}

bool	flood_fill_recursive(char **map_copy, int x, int y, t_data *data)
{
	if (!is_valid_position(x, y, data))
		return (true);
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return (false);
	if (is_boundary_position(x, y, data) && map_copy[y][x] != '1')
		return (true);
	map_copy[y][x] = 'V';
	if (flood_fill_recursive(map_copy, x + 1, y, data)
		|| flood_fill_recursive(map_copy, x - 1, y, data)
		|| flood_fill_recursive(map_copy, x, y + 1, data)
		|| flood_fill_recursive(map_copy, x, y - 1, data))
		return (true);
	return (false);
}
