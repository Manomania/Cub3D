/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_render_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:36:51 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/17 18:56:04 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "door_bonus.h"
#include "minimap_bonus.h"
#include "fps_extra.h"

void	handle_render_bonus_features(t_data *data)
{
	draw_minimap(data);
	update_door_animations(data);
}

void	handle_render_extra_features(t_data *data)
{
	update_fps_counter(data);
	display_fps(data);
}
