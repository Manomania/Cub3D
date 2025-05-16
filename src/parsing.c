/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:05:54 by maximart          #+#    #+#             */
/*   Updated: 2025/05/16 14:37:19 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_rgb(const char *color)
{
	int	rgb;

	if (!ft_isdigit(*color))
		return (true);
	rgb = ft_atoi(color);
	return (rgb);
}

bool	set_rgb(int *r, int *g, int *b, const char *color)
{
	if (ft_strchr(color, ' ') != 0 || ft_strchr(color, '-') != 0)
		return (true);
	*r = get_rgb(color);
	color = ft_strchr(color, ',');
	if (!color)
		return (true);
	color++;
	*g = get_rgb(color);
	color = ft_strchr(color, ',');
	if (!color)
		return (true);
	color++;
	*b = get_rgb(color);
	if (*r > 255 || *g > 255 || *b > 255)
		return (true);
	return (false);
}

bool	parse_rgb(t_data *data, const char *identifier, const char *color)
{
	int	r;
	int	g;
	int	b;

	if (set_rgb(&r, &g, &b, color))
		return (true);
	if (ft_strncmp(identifier, "F", 1) == 0)
	{
		data->floor_color[0] = r;
		data->floor_color[1] = g;
		data->floor_color[2] = b;
		return (false);
	}
	if (ft_strncmp(identifier, "C", 1) == 0)
	{
		data->ceil_color[0] = r;
		data->ceil_color[1] = g;
		data->ceil_color[2] = b;
		return (false);
	}
	return (true);
}

bool	parse_color(t_data *data, char *line, const char *identifier)
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
		if (parse_rgb(data, identifier, color))
			return (true);
	}
	return (false);
}

bool	parse_texture(t_data *data, char *line, const char *cardinal)
{
	char	*skip;
	char	*path;

	skip = line;
	while (*skip && (*skip == ' ' || *skip == '\t'))
		skip++;
	if (ft_strncmp(skip, cardinal, 3) == 0)
	{
		path = skip + 2;
		while (*path && (*path == ' ' || *path == '\t'))
			path++;
		if (ft_strcmp(cardinal, "NO ") == 0)
			data->texture_n = ft_strdup(path);
		else if (ft_strcmp(cardinal, "SO ") == 0)
			data->texture_s = ft_strdup(path);
		else if (ft_strcmp(cardinal, "WE ") == 0)
			data->texture_w = ft_strdup(path);
		else if (ft_strcmp(cardinal, "EA ") == 0)
			data->texture_e = ft_strdup(path);
		return (false);
	}
	return (true);
}

bool	check_parsing(t_data *data, char *line)
{
	if (line[0] == '\0')
		return (false);

	if (!parse_texture(data, line, "NO ") || !parse_texture(data, line, "SO ")
		|| !parse_texture(data, line, "WE ") || !parse_texture(data, line, "EA "))
		return (false);
	if (!parse_color(data, line, "F ") && !parse_color(data, line, "C "))
		return (false);
	return (true);
}

int	parse_file(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (1);
	while (line)
	{
		if (check_parsing(data, line))
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	printf(YELLOW"DEBUG: texture_north: %s\n"RESET, data->texture_n);
	printf(YELLOW"DEBUG: texture_south: %s\n"RESET, data->texture_s);
	printf(YELLOW"DEBUG: texture_west: %s\n"RESET, data->texture_w);
	printf(YELLOW"DEBUG: texture_east: %s\n"RESET, data->texture_e);
	printf(YELLOW"DEBUG: F color[r]: %d\n"RESET, data->floor_color[0]);
	printf(YELLOW"DEBUG: F color[g]: %d\n"RESET, data->floor_color[1]);
	printf(YELLOW"DEBUG: F color[b]: %d\n"RESET, data->floor_color[2]);
	printf(YELLOW"DEBUG: C color[r]: %d\n"RESET, data->ceil_color[0]);
	printf(YELLOW"DEBUG: C color[g]: %d\n"RESET, data->ceil_color[1]);
	printf(YELLOW"DEBUG: C color[b]: %d\n"RESET, data->ceil_color[2]);
	return (0);
}

int	read_file(t_data *data, const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return(1);
	}
	if (parse_file(data, fd))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}