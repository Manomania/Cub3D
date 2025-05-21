/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 11:42:38 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/21 16:39:04 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Making a whole file just for `move_player`, because it's big enough of a
** function.
*/

#include "player.h"

/*
** This function and `move_l_r` doubles as a very basic collision checker, but
** it kinda sucks, I want to scrape it eventually and make something proper.
*/
static void	move_fw_bw(t_player *player, char **map)
{
	double	new_pos_x;
	double	new_pos_y;

	if (player->move_forward)
	{
		new_pos_x = player->pos_x + player->dir_x * player->move_speed;
		new_pos_y = player->pos_y + player->dir_y * player->move_speed;
		if (map[(int)player->pos_y][(int)new_pos_x] != '1')
			player->pos_x = new_pos_x;
		if (map[(int)new_pos_y][(int)player->pos_x] != '1')
			player->pos_y = new_pos_y;
	}
	if (player->move_backward)
	{
		new_pos_x = player->pos_x - player->dir_x * player->move_speed;
		new_pos_y = player->pos_y - player->dir_y * player->move_speed;
		if (map[(int)player->pos_y][(int)new_pos_x] != '1')
			player->pos_x = new_pos_x;
		if (map[(int)new_pos_y][(int)player->pos_x] != '1')
			player->pos_y = new_pos_y;
	}
}

/*
** See `move_fw_bw` comment above.
*/
static void	move_l_r(t_player *player, char **map)
{
	double	new_pos_x;
	double	new_pos_y;

	if (player->move_left)
	{
		new_pos_x = player->pos_x - player->plane_x * player->move_speed;
		new_pos_y = player->pos_y - player->plane_y * player->move_speed;
		if (map[(int)player->pos_y][(int)new_pos_x] != '1')
			player->pos_x = new_pos_x;
		if (map[(int)new_pos_y][(int)player->pos_x] != '1')
			player->pos_y = new_pos_y;
	}
	if (player->move_right)
	{
		new_pos_x = player->pos_x + player->plane_x * player->move_speed;
		new_pos_y = player->pos_y + player->plane_y * player->move_speed;
		if (map[(int)player->pos_y][(int)new_pos_x] != '1')
			player->pos_x = new_pos_x;
		if (map[(int)new_pos_y][(int)player->pos_x] != '1')
			player->pos_y = new_pos_y;
	}
}

static void	rotate_l(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	if (player->rotate_left)
	{
		old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-player->rot_speed) - player->dir_y
			* sin(-player->rot_speed);
		player->dir_y = old_dir_x * sin(-player->rot_speed) + player->dir_y
			* cos(-player->rot_speed);
		old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(-player->rot_speed)
			- player->plane_y * sin(-player->rot_speed);
		player->plane_y = old_plane_x * sin(-player->rot_speed)
			+ player->plane_y * cos(-player->rot_speed);
	}
}

static void	rotate_r(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	if (player->rotate_right)
	{
		old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(player->rot_speed) - player->dir_y
			* sin(player->rot_speed);
		player->dir_y = old_dir_x * sin(player->rot_speed) + player->dir_y
			* cos(player->rot_speed);
		old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(player->rot_speed)
			- player->plane_y * sin(player->rot_speed);
		player->plane_y = old_plane_x * sin(player->rot_speed) + player->plane_y
			* cos(player->rot_speed);
	}
}

void	move_player(t_player *player, char **map)
{
	move_fw_bw(player, map);
	move_l_r(player, map);
	rotate_l(player);
	rotate_r(player);
}
