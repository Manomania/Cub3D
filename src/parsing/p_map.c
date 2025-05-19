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

void	get_dimension(t_data *data, char *line, bool is_map_line, char *og_tmp)
{
	int	len = 0;

	if (is_map_line)
	{
		len = (int)ft_strlen(line);
		if (len > data->map_width)
			data->map_width = len;
		data->map_height++;
	}
	free(og_tmp);
}

bool process_map_dimension(t_data *data, char *line)
{
	char	*tmp;
	char	*original_tmp;
	bool	is_map_line = true;

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
