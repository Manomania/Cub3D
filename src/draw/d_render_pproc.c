/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_render_pproc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:07:51 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 14:11:31 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file is for the conditional preprocessor statements that mess with the
** norm, as indicated by the `pproc` suffix.
*/

#include "cub3d.h"

#ifdef BONUS

void	handle_render_bonus_features(t_data *data)
{
	draw_minimap(data);
}
#else

void	handle_render_bonus_features(t_data *data)
{
	(void)data;
}
#endif