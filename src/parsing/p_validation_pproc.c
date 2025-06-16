/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_validation_pproc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:52:23 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 17:00:01 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef BONUS

bool	check_bonus_textures(t_data *data)
{
	if (!data->texture_door)
	{
		ft_printf(RED "Error\nMissing door texture (D)\n" RESET);
		return (true);
	}
	return (false);
}
#else

bool	check_bonus_textures(t_data *data)
{
	(void) data;
	return (false);
}
#endif
