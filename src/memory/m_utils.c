/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:59:05 by maximart          #+#    #+#             */
/*   Updated: 2025/05/21 16:36:24 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_map_array(t_data *data)
{
	if (data->map_height < 1)
		return (true);
	data->map = ft_calloc(data->map_height + 1, sizeof(char *));
	if (!data->map)
		return (true);
	return (false);
}
