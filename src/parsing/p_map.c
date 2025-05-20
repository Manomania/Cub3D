/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:57:14 by maximart          #+#    #+#             */
/*   Updated: 2025/05/19 13:44:47 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_map_line_valid(char *line)
{
	char	*tmp;
	char	*original_tmp;

	if (!line || line[0] == '\0')
		return (false);
	original_tmp = ft_strtrim(line, "\n");
	tmp = original_tmp;
	while (*tmp && *tmp == ' ')
		tmp++;
	if (*tmp == '\0')
	{
		free(original_tmp);
		return (true);
	}
	while (*tmp)
	{
		if (!ft_strchr("01 \tNSEW", *tmp))
		{
			free(original_tmp);
			return (true);
		}
		tmp++;
	}
	free(original_tmp);
	return (false);
}

static void	get_dimension(t_data *data, char *line, bool is_line, char *og_tmp)
{
	int	len;

	len = 0;
	if (is_line)
	{
		len = (int)ft_strlen(line);
		if (len > data->map_width)
			data->map_width = len;
		data->map_height++;
	}
	free(og_tmp);
}

bool	process_map_dimension(t_data *data, char *line)
{
	char	*tmp;
	char	*original_tmp;
	bool	is_map_line;

	is_map_line = true;
	if (line[0] == '\0')
		return (false);
	original_tmp = ft_strtrim(line, "\n");
	tmp = original_tmp;
	while (*tmp && *tmp == ' ')
		tmp++;
	if (*tmp == '\0')
	{
		free(original_tmp);
		return (true);
	}
	while (*tmp)
	{
		if (!ft_strchr("01 \tNSEW", *tmp))
			is_map_line = false;
		tmp++;
	}
	get_dimension(data, line, is_map_line, original_tmp);
	return (false);
}

static bool	read_map_content(t_data *data, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (true);
	while (line)
	{
		if (!is_map_line_valid(line))
		{
			data->map[i++] = ft_strdup(line);
			if (data->map[i])
			{
				free_map(data);
				free(line);
				return (true);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	data->map[i] = NULL;
	return (false);
}

bool	fill_map(t_data *data, int fd)
{
	if (init_map_array(data))
		return (true);
	if (read_map_content(data, fd))
		return (true);
	return (false);
}
