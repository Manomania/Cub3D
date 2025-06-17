/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_validation_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:54:20 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/17 14:54:29 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_bonus_textures(t_data *data)
{
	if (!data->texture_door)
	{
		ft_printf(RED "Error\nMissing door texture (D)\n" RESET);
		return (true);
	}
	return (false);
}
