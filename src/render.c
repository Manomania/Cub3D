/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:10:47 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/16 18:38:24 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "player.h"
#include "raycasting.h"

void	render_frame(t_data *data)
{
	// Move player based on input states
	move_player(&data->player, data->map);
	// Clear image buffer (optional)
	ft_memset(data->img.addr, 0, data->win_width * data->win_height
		* (data->img.bits_per_pixel / 8));
	// Perform raycasting and drawing
	raycasting(data);
	// Put image to window
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
