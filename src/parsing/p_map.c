/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:57:14 by maximart          #+#    #+#             */
/*   Updated: 2025/05/19 19:13:34 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "mem.h"

static bool	is_map_line_valid(char *line)
{
	char	*tmp;
	char	*original_tmp;
	bool	is_valid;

	is_valid = true;
	if (!line || line[0] == '\0')
		return (false);
	original_tmp = ft_strtrim(line, "\n");
	tmp = original_tmp;
	while (*tmp && *tmp == ' ')
		tmp++;
	if (*tmp == '\0')
	{
		free(original_tmp);
		return (false);
	}
	while (*tmp)
	{
		if (!ft_strchr("01 \tNSEW", *tmp))
			is_valid = false;
		tmp++;
	}
	free(original_tmp);
	return (is_valid);
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
	while (line && i < data->map_height)
	{
		if (is_map_line_valid(line))
		{
			data->map[i] = ft_strdup(line);
			if (!data->map[i])
			{
				free_map(data);
				free(line);
				return (true);
			}
			i++;
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
