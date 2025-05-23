/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_file.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:44:41 by maximart          #+#    #+#             */
/*   Updated: 2025/05/23 19:40:57 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include "parsing.h"

static bool	is_config_line(char *line)
{
	char	*trimmed;

	if (!line)
		return (false);
	trimmed = line;
	while (*trimmed && (*trimmed == ' ' || *trimmed == '\t'))
		trimmed++;
	if (ft_strncmp(trimmed, "NO ", 3) == 0)
		return (true);
	if (ft_strncmp(trimmed, "SO ", 3) == 0)
		return (true);
	if (ft_strncmp(trimmed, "WE ", 3) == 0)
		return (true);
	if (ft_strncmp(trimmed, "EA ", 3) == 0)
		return (true);
	if (ft_strncmp(trimmed, "F ", 2) == 0)
		return (true);
	if (ft_strncmp(trimmed, "C ", 2) == 0)
		return (true);
	return (false);
}

static bool	validate_post_map_line(t_data *data, char *line)
{
	if (!line || line[0] == '\0')
		return (false);
	if (data->map_started && is_config_line(line))
	{
		ft_printf(RED "Error\nMap isn't the last data found\n" RESET);
		data->error_detected = true;
		return (true);
	}
	return (false);
}

static bool	process_config_line(t_data *data, char *line)
{
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
	return (false);
}

static bool	process_line_enhanced(t_data *data, char *line)
{
	if (!line || line[0] == '\0')
		return (false);
	if (validate_post_map_line(data, line))
		return (true);
	if (process_config_line(data, line))
		return (false);
	if (is_map_line_valid(line))
		data->map_started = true;
	if (!process_map_dimension(data, line))
		return (false);
	return (false);
}

static bool	parse_config_enhanced(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (process_line_enhanced(data, line))
		{
			free(line);
			return (true);
		}
		if (data->error_detected)
		{
			free(line);
			return (true);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (false);
}

static bool	validate_remaining_content(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (validate_post_map_line(data, line))
		{
			free(line);
			return (true);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (false);
}

static bool	fill_map_enhanced(t_data *data, int fd)
{
	if (fd < 0)
	{
		close(fd);
		return (true);
	}
	data->map_started = true;
	if (fill_map(data, fd))
	{
		data->error_detected = true;
		return (true);
	}
	return (false);
}

int	read_file(t_data *data, const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	if (parse_config_enhanced(data, fd))
	{
		close(fd);
		return (1);
	}
	close(fd);
	fd = open(file, O_RDONLY);
	if (fill_map_enhanced(data, fd))
	{
		close(fd);
		return (1);
	}
	if (validate_remaining_content(data, fd))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}