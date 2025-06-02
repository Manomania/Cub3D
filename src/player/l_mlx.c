/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:03:34 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/21 16:49:27 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "draw.h"
#include "mem.h"
#include "mlx.h"
#include "player.h"
#include "mouse.h"

static void	hook_destroy(t_data *data)
{
	free_ressource(data);
	exit(EXIT_SUCCESS);
}

static int	key_press(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		hook_destroy(data);
	else if (keycode == W)
		data->player.move_forward = 1;
	else if (keycode == S)
		data->player.move_backward = 1;
	else if (keycode == A)
		data->player.move_left = 1;
	else if (keycode == D)
		data->player.move_right = 1;
	else if (keycode == LEFT_ARROW)
		data->player.rotate_left = 1;
	else if (keycode == RIGHT_ARROW)
		data->player.rotate_right = 1;
	else if (keycode == 32) // MOUSE
		mouse_toggle();
	return (0);
}

static int	key_release(int keycode, t_data *data)
{
	if (keycode == W)
		data->player.move_forward = 0;
	else if (keycode == S)
		data->player.move_backward = 0;
	else if (keycode == A)
		data->player.move_left = 0;
	else if (keycode == D)
		data->player.move_right = 0;
	else if (keycode == LEFT_ARROW)
		data->player.rotate_left = 0;
	else if (keycode == RIGHT_ARROW)
		data->player.rotate_right = 0;
	return (0);
}

void	setup_mlx_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx, (int (*)())render_frame, data);
	mlx_hook(data->win, ON_DESTROY, 0, (int (*)())hook_destroy, data);
	mlx_hook(data->win, ON_KEYDOWN, 1L << 0, key_press, data);
	mlx_hook(data->win, ON_KEYUP, 1L << 1, key_release, data);
	mouse_setup_hooks(data); // MOUSE
}
