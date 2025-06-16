/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_pproc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:48:31 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 19:12:53 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	handle_mlx_bonus_features(t_data *data, int keycode)
{
	double	check_distance;
	int		front_x;
	int		front_y;
	int		player_x;
	int		player_y;
	int		dx;
	int		dy;

	if (keycode == LMB)
		mouse_toggle();
	else if (keycode == SPACE)
	{
		check_distance = 1.8;
		front_x = (int)(data->player.pos_x + data->player.dir_x * check_distance);
		front_y = (int)(data->player.pos_y - data->player.dir_y * check_distance);
		if (front_x >= 0 && front_x < data->map_width && 
			front_y >= 0 && front_y < data->map_height &&
			data->map[front_y] && front_x < (int)ft_strlen(data->map[front_y]) &&
			data->map[front_y][front_x] == 'D')
		{
			toggle_door(data, front_x, front_y);
			return ;
		}
		player_x = (int)data->player.pos_x;
		player_y = (int)data->player.pos_y;
		dy = -2;
		while (++dy <= 1)
		{
			dx = -2;
			while (++dx <= 1)
			{
				int check_x = player_x + dx;
				int check_y = player_y + dy;
				
				if (check_x >= 0 && check_x < data->map_width &&
					check_y >= 0 && check_y < data->map_height &&
					data->map[check_y] && check_x < (int)ft_strlen(data->map[check_y]) &&
					data->map[check_y][check_x] == 'D')
				{
					toggle_door(data, check_x, check_y);
					return ;
				}
			}
		}
	}
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

void	handle_mlx_bonus_features(t_data *data, int keycode)
{
	(void)data;
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