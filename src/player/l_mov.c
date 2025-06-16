/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mov.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 11:42:38 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 16:11:35 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Making a whole file just for `move_player`, because it's big enough of a
** function.
*/

#include "player.h"

/*
** `l_mov_rot.c`
** No use making a header for you
*/
void	rotate_l(t_player *player);
void	rotate_r(t_player *player);
/*
** `l_mov_pproc.c`
*/
bool	is_valid_position(char **map, double x, double y);

/*
** Move forward/backward along the direction vector
** Fixed collision detection to be consistent regardless of camera angle
*/
static void	move_fw_bw(t_player *player, char **map)
{
	double	new_pos_x;
	double	new_pos_y;

	if (player->move_forward)
	{
		new_pos_x = player->pos_x + player->dir_x * player->move_speed;
		new_pos_y = player->pos_y - player->dir_y * player->move_speed;
		if (is_valid_position(map, new_pos_x, player->pos_y))
			player->pos_x = new_pos_x;
		if (is_valid_position(map, player->pos_x, new_pos_y))
			player->pos_y = new_pos_y;
	}
	if (player->move_backward)
	{
		new_pos_x = player->pos_x - player->dir_x * player->move_speed;
		new_pos_y = player->pos_y + player->dir_y * player->move_speed;
		if (is_valid_position(map, new_pos_x, player->pos_y))
			player->pos_x = new_pos_x;
		if (is_valid_position(map, player->pos_x, new_pos_y))
			player->pos_y = new_pos_y;
	}
}

/*
** Move left/right along the camera plane (strafe movement)
** Fixed collision detection to be consistent
*/
static void	move_l_r(t_player *player, char **map)
{
	double	new_pos_x;
	double	new_pos_y;

	if (player->move_left)
	{
		new_pos_x = player->pos_x + player->plane_x * player->move_speed;
		new_pos_y = player->pos_y - player->plane_y * player->move_speed;
		if (is_valid_position(map, new_pos_x, player->pos_y))
			player->pos_x = new_pos_x;
		if (is_valid_position(map, player->pos_x, new_pos_y))
			player->pos_y = new_pos_y;
	}
	if (player->move_right)
	{
		new_pos_x = player->pos_x - player->plane_x * player->move_speed;
		new_pos_y = player->pos_y + player->plane_y * player->move_speed;
		if (is_valid_position(map, new_pos_x, player->pos_y))
			player->pos_x = new_pos_x;
		if (is_valid_position(map, player->pos_x, new_pos_y))
			player->pos_y = new_pos_y;
	}
}

void	move_player(t_player *player, char **map)
{
	move_fw_bw(player, map);
	move_l_r(player, map);
	rotate_l(player);
	rotate_r(player);
}
