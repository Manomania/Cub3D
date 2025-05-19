/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:44:41 by maximart          #+#    #+#             */
/*   Updated: 2025/05/16 21:44:41 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	process_line(t_data *data, char *line)
{
	if (line[0] == '\0')
		return (false);
	if (!parse_texture_path(data, line, "NO ")
		|| !parse_texture_path(data, line, "SO ")
		|| !parse_texture_path(data, line, "WE ")
		|| !parse_texture_path(data, line, "EA "))
		return (false);
	if (!process_map_dimension(data, line))
		return (false);
	if (!parse_color_line(data, line, "F ")
		&& !parse_color_line(data, line, "C "))
		return (false);
	return (true);
}

static int	parse_config_file(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (1);
	while (line)
	{
		if (process_line(data, line))
		{
			free(line);
			return (1);
		}
		if (process_map_dimension(data, line))
		{
			free(line);
			return (1);
		}
		// if (process_fill_map(data, line))
		// {
		// 	free(line);
		// 	return (1);
		// }
		free(line);
		line = get_next_line(fd);
	}
	printf(YELLOW"\nDEBUG: texture_north: %s\n"RESET, data->texture_n);
	printf(YELLOW"DEBUG: texture_south: %s\n"RESET, data->texture_s);
	printf(YELLOW"DEBUG: texture_west: %s\n"RESET, data->texture_w);
	printf(YELLOW"DEBUG: texture_east: %s\n"RESET, data->texture_e);
	printf(YELLOW"DEBUG: F color[r]: %d\n"RESET, data->floor_color[0]);
	printf(YELLOW"DEBUG: F color[g]: %d\n"RESET, data->floor_color[1]);
	printf(YELLOW"DEBUG: F color[b]: %d\n"RESET, data->floor_color[2]);
	printf(YELLOW"DEBUG: C color[r]: %d\n"RESET, data->ceil_color[0]);
	printf(YELLOW"DEBUG: C color[g]: %d\n"RESET, data->ceil_color[1]);
	printf(YELLOW"DEBUG: C color[b]: %d\n"RESET, data->ceil_color[2]);
	printf(YELLOW"DEBUG: HEIGHT: %d\n"RESET, data->map_width);
	printf(YELLOW"DEBUG: WIDTH: %d\n"RESET, data->map_height);
	return (0);
}

int	read_file(t_data *data, const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (1);
	}
	if (parse_config_file(data, fd))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
