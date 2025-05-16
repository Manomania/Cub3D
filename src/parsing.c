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

bool	parse_color(t_data *data, char *line, const char *identifier)
{
	char	*skip;
	char	*color;

	skip = line;
	while (*skip && (*skip == ' ' || *skip == '\t'))
		skip++;
	if (ft_strncmp(skip, identifier, 1) == 0)
	{
		color = ft_strdup(skip + 1);
		while (*color && (*color == ' ' || *color == '\t'))
			color++;
		if (ft_strcmp(identifier, "F") == 0)
			data->floor_color = ft_strdup(color);
		if (ft_strcmp(identifier, "C") == 0)
			data->ceil_color = ft_strdup(color);
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
	if (ft_strncmp(skip, cardinal, 2) == 0)
	{
		path = ft_strdup(skip + 3);
		while (*path && (*path == ' ' || *path == '\t'))
			path++;
		if (ft_strcmp(cardinal, "NO") == 0)
			data->texture_n = ft_strdup(path);
		if (ft_strcmp(cardinal, "SO") == 0)
			data->texture_s = ft_strdup(path);
		if (ft_strcmp(cardinal, "WE") == 0)
			data->texture_w = ft_strdup(path);
		if (ft_strcmp(cardinal, "EA") == 0)
			data->texture_e = ft_strdup(path);
		return (true);
	}
	return (false);
}

void	check_parsing(t_data *data, char *line)
{
	parse_texture(data, line, "NO");
	parse_texture(data, line, "SO");
	parse_texture(data, line, "WE");
	parse_texture(data, line, "EA");
	parse_color(data, line, "C");
	parse_color(data, line, "F");
}

int	parse_map(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (1);
	while (line)
	{
		check_parsing(data, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	printf(YELLOW"DEBUG: texture_north: %s\n"RESET, data->texture_n);
	printf(YELLOW"DEBUG: texture_south: %s\n"RESET, data->texture_s);
	printf(YELLOW"DEBUG: texture_west: %s\n"RESET, data->texture_w);
	printf(YELLOW"DEBUG: texture_east: %s\n"RESET, data->texture_e);
	printf(YELLOW"DEBUG: F color: %s\n"RESET, data->floor_color);
	printf(YELLOW"DEBUG: C color: %s\n"RESET, data->ceil_color);
	return (0);
}

int	read_file(t_data *data, const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		//TODO clearexit
		return(1);
	}
	if (parse_map(data, fd))
	{
		//TODO clearexit
		return (1);
	}
	close(fd);
	return (0);
}