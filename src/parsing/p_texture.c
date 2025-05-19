/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:46:09 by maximart          #+#    #+#             */
/*   Updated: 2025/05/16 21:46:09 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_texture_path(t_data *data, char *line, const char *cardinal)
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
			data->texture_n = ft_strtrim(path, "\n");
		else if (ft_strcmp(cardinal, "SO ") == 0)
			data->texture_s = ft_strtrim(path, "\n");
		else if (ft_strcmp(cardinal, "WE ") == 0)
			data->texture_w = ft_strtrim(path, "\n");
		else if (ft_strcmp(cardinal, "EA ") == 0)
			data->texture_e = ft_strtrim(path, "\n");
		return (false);
	}
	return (true);
}
