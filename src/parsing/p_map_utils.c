/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:20:23 by maximart          #+#    #+#             */
/*   Updated: 2025/05/23 10:20:23 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	is_map_line_valid(char *line)
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
