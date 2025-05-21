/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_file.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:44:41 by maximart          #+#    #+#             */
/*   Updated: 2025/05/19 19:13:30 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mem.h>

#include "parsing.h"

static bool	process_line(t_data *data, char *line)
{
	if (line[0] == '\0')
		return (false);
	if (!parse_texture_path(data, line, "NO "))
		return (true);
	if (!parse_texture_path(data, line, "SO "))
		return (true);
	if (!parse_texture_path(data, line, "WE "))
		return (true);
	if (!parse_texture_path(data, line, "EA "))
		return (true);
	if (!parse_color_line(data, line, "F "))
		return (true);
	if (!parse_color_line(data, line, "C "))
		return (true);
	if (!process_map_dimension(data, line))
		return (true);
	return (false);
}

static bool	parse_config_file(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (true);
	while (line)
	{
		if (process_line(data, line))
		{
			if (data->error_detected)
			{
				free(line);
				break ;
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	return (false);
}

static bool	fd_fill_map(t_data *data, int fd)
{
	if (fd < 0)
	{
		close(fd);
		return (true);
	}
	if (fill_map(data, fd))
	{
		close(fd);
		data->error_detected = true;
		return (true);
	}
	close(fd);
	return (false);
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
		free_ressource(data);
		return (1);
	}
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd_fill_map(data, fd))
		return (1);
	return (0);
}
