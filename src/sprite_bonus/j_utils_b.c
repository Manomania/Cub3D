/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_utils_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:40:35 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/20 14:03:27 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "sprite_bonus.h"
#include <math.h>
#include <unistd.h>

t_texture	*get_sprite_texture(t_sprite *sprite)
{
	if (!sprite || !sprite->active)
		return (NULL);
	if (sprite->animation.current_frame >= sprite->animation.frame_count)
		return (NULL);
	return (&sprite->animation.frames[sprite->animation.current_frame]);
}

bool	is_sprite_visible(t_data *data, t_sprite *sprite)
{
	double	dx;
	double	dy;
	double	distance;
	double	angle_to_sprite;
	double	player_angle;
	double	angle_diff;

	if (!sprite->active)
		return (false);
	dx = sprite->x - data->player.pos_x;
	dy = sprite->y - data->player.pos_y;
	distance = sqrt(dx * dx + dy * dy);
	if (distance > 20.0)
		return (false);
	angle_to_sprite = atan2(dy, dx);
	player_angle = atan2(data->player.dir_y, data->player.dir_x);
	angle_diff = angle_to_sprite - player_angle;
	while (angle_diff > M_PI)
		angle_diff -= 2 * M_PI;
	while (angle_diff < -M_PI)
		angle_diff += 2 * M_PI;
	if (fabs(angle_diff) > M_PI / 2)
		return (false);
	return (true);
}