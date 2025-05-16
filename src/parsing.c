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

int	parse_map(t_data *data, int fd)
{
	char	*line;
	// char	*trimmed;

	line = get_next_line(fd);
	if (!line)
		return (1);
	while (line)
	{
		if (ft_strcmp(line, "NO") == 0)
			data->texture_n = line;
		line = get_next_line(fd);
	}
	printf(YELLOW"DEBUG: %s\n"RESET, data->texture_n);
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