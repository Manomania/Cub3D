/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:46:59 by maximart          #+#    #+#             */
/*   Updated: 2025/05/19 19:12:04 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	check_color_line(char *color)
{
	char	*check;
	int		count_comma;

	count_comma = 0;
	check = color;
	while (*check)
	{
		if (*check == ',')
			count_comma++;
		if ((!ft_isdigit(*check) && *check != ',' && *check != '\n'))
		{
			printf(RED "Error: Invalid character in color: '%c'\n" RESET,
				*check);
			return (true);
		}
		check++;
	}
	if (count_comma != 2)
		return (true);
	return (false);
}

static bool	get_color_floor(t_data *data, char *color)
{
	data->floor_color.red = ft_atoi(color);
	while (*color && *color != ',')
		color++;
	if (!*color)
		return (true);
	color++;
	data->floor_color.green = ft_atoi(color);
	while (*color && *color != ',')
		color++;
	if (!*color)
		return (true);
	color++;
	data->floor_color.blue = ft_atoi(color);
	return (false);
}

static bool	get_color_ceil(t_data *data, char *color)
{
	data->floor_color.red = ft_atoi(color);
	while (*color && *color != ',')
		color++;
	if (!*color)
		return (true);
	color++;
	data->floor_color.green = ft_atoi(color);
	while (*color && *color != ',')
		color++;
	if (!*color)
		return (true);
	color++;
	data->floor_color.green = ft_atoi(color);
	return (false);
}

static bool	get_colors(t_data *data, char *color, const char *id)
{
	if (ft_strcmp(id, "F ") == 0)
	{
		if (get_color_floor(data, color))
			return (true);
		return (false);
	}
	if (ft_strcmp(id, "C ") == 0)
	{
		if (get_color_ceil(data, color))
			return (true);
		return (false);
	}
	return (true);
}

bool	parse_color_line(t_data *data, char *line, const char *id)
{
	char	*skip;
	char	*color;

	skip = line;
	while (*skip && (*skip == ' ' || *skip == '\t'))
		skip++;
	if (ft_strncmp(skip, id, 2) != 0)
		return (true);
	color = skip + 2;
	while (*color && (*color == ' ' || *color == '\t'))
		color++;
	if (check_color_line(color))
		return (true);
	if (get_colors(data, color, id))
		return (true);
	return (false);
}
