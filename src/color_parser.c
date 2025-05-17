/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:46:59 by maximart          #+#    #+#             */
/*   Updated: 2025/05/16 21:46:59 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_color_line(t_data *data, char *line, const char *id)
{
	char	*skip;
	char	*color;
	int		r = 0;
	int		g = 0;
	int		b = 0;

	skip = line;
	while (*skip && (*skip == ' ' || *skip == '\t'))
		skip++;
	if (ft_strncmp(skip, id, 2) == 0)
	{
		color = skip + 2;
		while (*color && (*color == ' ' || *color == '\t'))
			color++;
		if (ft_strcmp(id, "F ") == 0)
		{
			r = ft_atoi(color);
			data->floor_color[0] = r;
			while (*color && *color != ',')
				color++;
			if (*color == ',')
				color++;
			g = ft_atoi(color);
			data->floor_color[1] = g;
			while (*color && *color != ',')
				color++;
			if (*color == ',')
				color++;
			b = ft_atoi(color);
			data->floor_color[2] = b;
			if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
				return (true);
			return (false);
		}
		if (ft_strcmp(id, "C ") == 0)
		{
			r = ft_atoi(color);
			data->ceil_color[0] = r;
			while (*color && *color != ',')
				color++;
			if (*color == ',')
				color++;
			g = ft_atoi(color);
			data->ceil_color[1] = g;
			while (*color && *color != ',')
				color++;
			if (*color == ',')
				color++;
			b = ft_atoi(color);
			data->ceil_color[2] = b;
			if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
				return (true);
			return (false);
		}
		return (false);
	}
	return (false);
}
