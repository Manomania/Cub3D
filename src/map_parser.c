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

bool	process_map_dimension(t_data *data, char *line)
{
	// int	i = 0;
	if (line[0] == '\0')
		return (false);
	while (*line && *line == ' ')
		line++;
	// printf(YELLOW"DEBUG: "RESET);
	if (ft_strcmp(line, "1") == 0)
	{
		if (!data->map_width)
			data->map_width = (int)ft_strlen(line);
		data->map_height++;
		return (false);
	}
	return (true);
}
