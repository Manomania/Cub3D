/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_system_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:00:20 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/17 14:11:24 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_door_system(t_data *data)
{
	int	x;
	int	y;

	data->door_system.door_capacity = 100;
	data->door_system.door_count = 0;
	data->door_system.animation_speed = 3.0f;
	data->door_system.doors = ft_calloc(data->door_system.door_capacity,
			sizeof(t_door));
	if (!data->door_system.doors)
	{
		ft_printf(RED "Error\nFailed to allocate memory for door system\n" RESET);
		return ;
	}
	y = -1;
	while (++y < data->map_height)
	{
		x = -1;
		while (++x < data->map_width && data->map[y]
			&& x < (int)ft_strlen(data->map[y]))
		{
			if (data->map[y][x] == 'D')
			{
				if (data->door_system.door_count < data->door_system.door_capacity)
				{
					data->door_system.doors[data->door_system.door_count].x = x;
					data->door_system.doors[data->door_system.door_count].y = y;
					data->door_system.doors[data->door_system.door_count].is_open = false;
					data->door_system.doors[data->door_system.door_count].is_opening = false;
					data->door_system.doors[data->door_system.door_count].is_closing = false;
					data->door_system.doors[data->door_system.door_count].open_progress = 0.0f;
					data->door_system.door_count++;
				}
			}
		}
	}
}

void	update_door_animations(t_data *data)
{
	int		i;
	t_door	*door;

	i = -1;
	while (++i < data->door_system.door_count)
	{
		door = &data->door_system.doors[i];
		if (door->is_opening)
		{
			door->open_progress += data->door_system.animation_speed
				* data->delta_time;
			if (door->open_progress >= 1.0f)
			{
				door->open_progress = 1.0f;
				door->is_opening = false;
				door->is_open = true;
			}
		}
		else if (door->is_closing)
		{
			door->open_progress -= data->door_system.animation_speed
				* data->delta_time;
			if (door->open_progress <= 0.0f)
			{
				door->open_progress = 0.0f;
				door->is_closing = false;
				door->is_open = false;
			}
		}
	}
}

t_door	*get_door_at(t_data *data, int x, int y)
{
	int	i;

	i = -1;
	while (++i < data->door_system.door_count)
	{
		if (data->door_system.doors[i].x == x && data->door_system.doors[i].y == y)
			return (&data->door_system.doors[i]);
	}
	return (NULL);
}

void	toggle_door(t_data *data, int x, int y)
{
	t_door	*door;

	door = get_door_at(data, x, y);
	if (!door)
		return ;
	if (door->is_open || door->is_opening)
	{
		door->is_open = false;
		door->is_opening = false;
		door->is_closing = true;
	}
	else if (!door->is_open || door->is_closing)
	{
		door->is_open = false;
		door->is_closing = false;
		door->is_opening = true;
	}
}

bool	is_door_passable(t_data *data, int x, int y)
{
	t_door	*door;

	door = get_door_at(data, x, y);
	if (!door)
		return (false);
	return (door->open_progress > 0.7f);
}

void	free_door_system(t_data *data)
{
	if (data->door_system.doors)
	{
		free(data->door_system.doors);
		data->door_system.doors = NULL;
	}
	data->door_system.door_count = 0;
	data->door_system.door_capacity = 0;
}
