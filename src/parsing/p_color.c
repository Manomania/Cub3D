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

#include "../../include/cub3d.h"

bool parse_color_line(t_data *data, char *line, const char *id)
{
	char	*skip;
	char	*color;
	// char	*og_color;
	char	*check;
	int		r = 0;
	int		g = 0;
	int		b = 0;

	skip = line;
	while (*skip && (*skip == ' ' || *skip == '\t'))
		skip++;
	if (ft_strncmp(skip, id, 2) != 0)
		return (true);
	color = skip + 2;
	while (*color && (*color == ' ' || *color == '\t'))
		color++;
	check = color;
	printf(BLUE"DEBUG: %s"RESET, check);
	while (*check)
	{
		if (!ft_isdigit(*check) && *check != ',')
		{
			printf(RED"Error: Invalid character in color: '%c'\n"RESET, *check);
			return (true);
		}
		check++;
	}
	if (ft_strcmp(id, "F ") == 0)
	{
		r = ft_atoi(color);
		while (*color && *color != ',')
			color++;
		if (!*color) return (true);
		color++;
		g = ft_atoi(color);
		while (*color && *color != ',')
			color++;
		if (!*color) return (true);
		color++;
		b = ft_atoi(color);
		data->floor_color[0] = r;
		data->floor_color[1] = g;
		data->floor_color[2] = b;
		// free(og_color);
		if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		{
			printf(RED"Error: RGB values must be between 0 and 255\n"RESET);
			return (true);
		}
		return (false);
	}
	if (ft_strcmp(id, "C ") == 0)
	{
		r = ft_atoi(color);
		while (*color && *color != ',')
			color++;
		if (!*color) return (true);
		color++;
		g = ft_atoi(color);
		while (*color && *color != ',')
			color++;
		if (!*color) return (true);
		color++;
		b = ft_atoi(color);
		data->ceil_color[0] = r;
		data->ceil_color[1] = g;
		data->ceil_color[2] = b;
		// free(og_color);
		if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		{
			printf(RED"Error: RGB values must be between 0 and 255\n"RESET);
			return (true);
		}
		return (false);
	}
	// free(og_color);
	return (true);
}
