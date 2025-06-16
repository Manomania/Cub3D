/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:03:34 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 14:08:45 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mem.h"
#include "player.h"

/*
** `l_mlx_pproc.c`
** Not worth using a header file
*/
void	handle_mlx_bonus_features(int keycode);

void	hook_destroy(t_data *data)
{
	free_ressource(data);
	exit(EXIT_SUCCESS);
}

int	key_press(int keycode, t_data *data)
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
	else
		handle_mlx_bonus_features(keycode);
	return (0);
}

int	key_release(int keycode, t_data *data)
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