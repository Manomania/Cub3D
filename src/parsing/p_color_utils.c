/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_colors_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:39:34 by maximart          #+#    #+#             */
/*   Updated: 2025/05/21 15:39:34 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	check_color_line(t_data *data, char *color)
{
	char	*check;
	int		count_comma;

	count_comma = 0;
	check = color;
	while (*check)
	{
		if (*check == ',')
			count_comma++;
		if ((!ft_isdigit(*check) && *check != ',' && *check != '\n'))
		{
			ft_printf(RED "Error: Color values must be between 0-255\n" RESET);
			{
				data->error_detected = true;
				return (true);
			}
		}
		check++;
	}
	if (count_comma != 2)
		return (true);
	return (false);
}

bool	check_rgb_range(t_data *data, int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_printf(RED "Error: Color values must be between 0-255\n" RESET);
		data->error_detected = true;
		return (true);
	}
	return (false);
}
