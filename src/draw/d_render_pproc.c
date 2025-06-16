/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_render_pproc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:07:51 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 19:21:19 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_bonus.h"
#include "cub3d_extra.h"

#ifdef BONUS

void	handle_render_bonus_features(t_data *data)
{
	draw_minimap(data);
	update_door_animations(data);
	printf("Updating door animation\n");
}
#else

void	handle_render_bonus_features(t_data *data)
{
	(void)data;
}
#endif

#ifdef EXTRA

void	handle_render_extra_features(t_data *data)
{
	update_fps_counter(data);
	display_fps(data);
}
#else

void	handle_render_extra_features(t_data *data)
{
	(void)data;
}
#endif