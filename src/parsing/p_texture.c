/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:46:09 by maximart          #+#    #+#             */
/*   Updated: 2025/06/17 17:24:06 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

static bool	check_text_duplicate(t_data *data, const char *cardinal, char *exist)
{
	if (exist)
	{
		data->error_detected = true;
		ft_printf(RED"Error\nDuplicate texture for %s\n"RESET, cardinal);
		return (true);
	}
	return (false);
}


bool	parse_texture_path(t_data *data, char *line, const char *cardinal)
{
	char	*skip;
	char	*path;

	skip = line;
	while (*skip && (*skip == ' ' || *skip == '\t'))
		skip++;
	if (!ft_strncmp(skip, cardinal, ft_strlen(cardinal)))
	{
		path = skip + 2;
		while (*path && (*path == ' ' || *path == '\t'))
			path++;
		if (ft_strcmp(cardinal, "NO ") == 0)
		{
			if (check_text_duplicate(data, cardinal, data->texture_n))
				return (false);
			data->texture_n = ft_strtrim(path, "\n");
		}
		else if (ft_strcmp(cardinal, "SO ") == 0)
		{
			if (check_text_duplicate(data, cardinal, data->texture_s))
				return (false);
			data->texture_s = ft_strtrim(path, "\n");
		}
		else if (ft_strcmp(cardinal, "WE ") == 0)
		{
			if (check_text_duplicate(data, cardinal, data->texture_w))
				return (false);
			data->texture_w = ft_strtrim(path, "\n");
		}
		else if (ft_strcmp(cardinal, "EA ") == 0)
		{
			if (check_text_duplicate(data, cardinal, data->texture_e))
				return (false);
			data->texture_e = ft_strtrim(path, "\n");
		}
		else if (ft_strcmp(cardinal, "D ") == 0)
		{
			if (check_text_duplicate(data, cardinal, data->texture_door))
				return (false);
			data->texture_door = ft_strtrim(path, "\n");
		}
		return (false);
	}
	return (true);
}
