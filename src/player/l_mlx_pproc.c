/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_pproc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:48:31 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 14:47:12 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file is for the conditional preprocessor statements that mess with the
** norm, as indicated by the `pproc` suffix.
*/

#include "cub3d.h"
#include "cub3d_bonus.h"
#include "draw.h"
#include "mlx.h"
#include "player.h"

/*
** `l_mlx.c`
** Not worth using a header file
*/
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
void	hook_destroy(t_data *data);

#ifdef BONUS

void	handle_mlx_bonus_features(int keycode)
{
	if (keycode == 32)
		mouse_toggle();
}

void	setup_mlx_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx, (int (*)())render_frame, data);
	mlx_hook(data->win, ON_DESTROY, 0, (int (*)())hook_destroy, data);
	mlx_hook(data->win, ON_KEYDOWN, 1L << 0, key_press, data);
	mlx_hook(data->win, ON_KEYUP, 1L << 1, key_release, data);
	mouse_setup_hooks(data);
}
#else

void	handle_mlx_bonus_features(int keycode)
{
	(void)keycode;
}

void	setup_mlx_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx, (int (*)())render_frame, data);
	mlx_hook(data->win, ON_DESTROY, 0, (int (*)())hook_destroy, data);
	mlx_hook(data->win, ON_KEYDOWN, 1L << 0, key_press, data);
	mlx_hook(data->win, ON_KEYUP, 1L << 1, key_release, data);
}
#endif