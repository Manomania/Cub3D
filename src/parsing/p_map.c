/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:57:14 by maximart          #+#    #+#             */
/*   Updated: 2025/05/21 16:38:47 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include "parsing.h"

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
		return (false);
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

static bool	store_map_line(t_data *data, char *line, int index)
{
	data->map[index] = ft_strdup(line);
	if (!data->map[index])
	{
		free_map(data);
		return (true);
	}
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
			if (store_map_line(data, line, i))
			{
				free(line);
				return (true);
			}
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
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
