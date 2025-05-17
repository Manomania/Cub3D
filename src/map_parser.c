/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:57:14 by maximart          #+#    #+#             */
/*   Updated: 2025/05/17 17:57:14 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool    process_map(t_data *data, char *line)
{
	int		i;
	int		j;
	// int		k;

	i = 0;
	if (line[i] && line[i] == '1' && line[i] == ' ')
	{
		if (data->map == NULL)
			data->map = ft_calloc(50, sizeof(char *));
		if (data->map[data->map_x] == NULL)
			data->map[data->map_x] = ft_calloc(50, sizeof(char));
		j = 0;
		while (line[i] && (line[i] != '\n' || line[i] == '1'))
		{
			data->map[data->map_x][j] = line[i];
			i++;
			j++;
		}
		data->map[data->map_x][j] = '\0';
		printf(YELLOW"DEBUG: Map line : [%s]\n"RESET, data->map[data->map_x]);
		if (j > data->map_width)
			data->map_width = j;
		data->map_x++;
		data->map_height = data->map_x - 1;
		return (false);
	}
	return (true);
}
