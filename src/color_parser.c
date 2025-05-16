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

static int	extract_rgb_value(const char *color)
{
	int	rgb;

	if (!ft_isdigit(*color))
		return (true);
	rgb = ft_atoi(color);
	return (rgb);
}

static bool	set_rgb_values(int *r, int *g, int *b, const char *color)
{
	if (ft_strchr(color, ' ') != 0 || ft_strchr(color, '-') != 0)
		return (true);
	*r = extract_rgb_value(color);
	color = ft_strchr(color, ',');
	if (!color)
		return (true);
	color++;
	*g = extract_rgb_value(color);
	color = ft_strchr(color, ',');
	if (!color)
		return (true);
	color++;
	*b = extract_rgb_value(color);
	if (*r > 255 || *g > 255 || *b > 255)
		return (true);
	return (false);
}

static bool	parse_rgb_value(t_data *data, const char *id, const char *color)
{
	int	r;
	int	g;
	int	b;

	if (set_rgb_values(&r, &g, &b, color))
		return (true);
	if (ft_strncmp(id, "F", 1) == 0)
	{
		data->floor_color[0] = r;
		data->floor_color[1] = g;
		data->floor_color[2] = b;
		return (false);
	}
	if (ft_strncmp(id, "C", 1) == 0)
	{
		data->ceil_color[0] = r;
		data->ceil_color[1] = g;
		data->ceil_color[2] = b;
		return (false);
	}
	return (true);
}

bool	parse_color_line(t_data *data, char *line, const char *identifier)
{
	char	*skip;
	char	*color;

	skip = line;
	while (*skip && (*skip == ' ' || *skip == '\t'))
		skip++;
	if (ft_strncmp(skip, identifier, 2) == 0)
	{
		color = skip + 1;
		while (*color && (*color == ' ' || *color == '\t'))
			color++;
		if (parse_rgb_value(data, identifier, color))
			return (true);
	}
	return (false);
}
