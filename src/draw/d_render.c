/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:10:47 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/20 19:31:31 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
#include "player.h"
#include "raycasting.h"

/*
** Rendering pipeline. Note: we memset the image to zero, idk if it's a good
** idea.
*/
void	render_frame(t_data *data)
{
	if (!should_render_frame(data))
		return ;
	data->player.move_speed = BASE_MOVE_SPEED * data->delta_time;
	data->player.rot_speed = BASE_ROT_SPEED * data->delta_time;
	if (data->player.move_speed > 0.2)
		data->player.move_speed = 0.2;
	if (data->player.rot_speed > 0.15)
		data->player.rot_speed = 0.15;
	move_player(&data->player, data->map);
	ft_memset(data->img.addr, 0, data->win_width * data->win_height
		* (data->img.bits_per_pixel / 8));
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	update_fps_counter(data);
	display_fps(data);
}
