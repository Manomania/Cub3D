/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:49:24 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/16 17:19:12 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_data *data)
{
	char	dir;
	int		x;
	int		y;

	y = -1;
	dir = '\0';
	// Find player position and direction in map
	while (++y < data->map_height)
	{
		x = -1;
		while (++x < data->map_width)
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				// Save player position (centered in the tile)
				data->player->pos_x = x + 0.5;
				data->player->pos_y = y + 0.5;
				// Save player direction
				dir = data->map[y][x];
				// Set the map tile to empty
				data->map[y][x] = '0';
				// Exit loops once player is found
				x = data->map_width;
				y = data->map_height;
			}
		}
	}
	// Set initial direction and camera plane based on starting direction
	if (dir == 'N')
	{
		data->player->dir_x = 0;
		data->player->dir_y = -1;
		data->player->plane_x = 0.66;
		data->player->plane_y = 0;
	}
	else if (dir == 'S')
	{
		data->player->dir_x = 0;
		data->player->dir_y = 1;
		data->player->plane_x = -0.66;
		data->player->plane_y = 0;
	}
	else if (dir == 'E')
	{
		data->player->dir_x = 1;
		data->player->dir_y = 0;
		data->player->plane_x = 0;
		data->player->plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		data->player->dir_x = -1;
		data->player->dir_y = 0;
		data->player->plane_x = 0;
		data->player->plane_y = -0.66;
	}
	// Set movement and rotation speeds
	data->player->move_speed = 0.05;
	data->player->rot_speed = 0.03;
	// Initialize movement flags
	data->player->move_forward = 0;
	data->player->move_backward = 0;
	data->player->move_left = 0;
	data->player->move_right = 0;
	data->player->rotate_left = 0;
	data->player->rotate_right = 0;
	// Set camera height
	data->player->cam_height = data->win_height / 2.0;
}

/*
** Move the player based on the current control state and collision detection
*/
void	move_player(t_player *player, char **map)
{
	double	new_pos_x;
	double	new_pos_y;
	double	old_dir_x;
	double	old_plane_x;

	// Move forward or backward
	if (player->move_forward)
	{
		new_pos_x = player->pos_x + player->dir_x * player->move_speed;
		new_pos_y = player->pos_y + player->dir_y * player->move_speed;
		// Check for collisions
		if (map[(int)player->pos_y][(int)new_pos_x] != '1')
			player->pos_x = new_pos_x;
		if (map[(int)new_pos_y][(int)player->pos_x] != '1')
			player->pos_y = new_pos_y;
	}
	if (player->move_backward)
	{
		new_pos_x = player->pos_x - player->dir_x * player->move_speed;
		new_pos_y = player->pos_y - player->dir_y * player->move_speed;
		// Check for collisions
		if (map[(int)player->pos_y][(int)new_pos_x] != '1')
			player->pos_x = new_pos_x;
		if (map[(int)new_pos_y][(int)player->pos_x] != '1')
			player->pos_y = new_pos_y;
	}
	// Move left or right (sideways, perpendicular to direction)
	if (player->move_left)
	{
		new_pos_x = player->pos_x - player->plane_x * player->move_speed;
		new_pos_y = player->pos_y - player->plane_y * player->move_speed;
		// Check for collisions
		if (map[(int)player->pos_y][(int)new_pos_x] != '1')
			player->pos_x = new_pos_x;
		if (map[(int)new_pos_y][(int)player->pos_x] != '1')
			player->pos_y = new_pos_y;
	}
	if (player->move_right)
	{
		new_pos_x = player->pos_x + player->plane_x * player->move_speed;
		new_pos_y = player->pos_y + player->plane_y * player->move_speed;
		// Check for collisions
		if (map[(int)player->pos_y][(int)new_pos_x] != '1')
			player->pos_x = new_pos_x;
		if (map[(int)new_pos_y][(int)player->pos_x] != '1')
			player->pos_y = new_pos_y;
	}
	// Rotate view left or right
	if (player->rotate_left)
	{
		// Rotate direction and camera plane vectors using rotation matrix
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
	if (player->rotate_right)
	{
		// Rotate direction and camera plane vectors using rotation matrix
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
