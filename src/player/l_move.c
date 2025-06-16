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
** Check if a position is valid (not a wall)
*/
static bool	is_valid_position(char **map, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0 || !map[map_y] || !map[map_y][map_x])
		return (false);
	if (map[map_y][map_x] == '1')
		return (false);
	return (true);
}

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

static void	rotate_l(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	if (player->rotate_left)
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

static void	rotate_r(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	if (player->rotate_right)
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

void	move_player(t_player *player, char **map)
{
	move_fw_bw(player, map);
	move_l_r(player, map);
	rotate_l(player);
	rotate_r(player);
}
