/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:59:05 by maximart          #+#    #+#             */
/*   Updated: 2025/05/16 17:59:05 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_data(t_data *data)
{
	if (!data)
		return;
	if (data->texture_n)
		free(data->texture_n);
	if (data->texture_s)
		free(data->texture_s);
	if (data->texture_w)
		free(data->texture_w);
	if (data->texture_e)
		free(data->texture_e);
	free(data);
}