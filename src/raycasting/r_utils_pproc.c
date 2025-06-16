/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils_pproc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:35:27 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 19:41:11 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

#ifdef BONUS

void	apply_door_animation(t_data *data, t_ray *ray)
{
	int		map_x, map_y;
	t_door	*door;
	int		door_offset;

	if (ray->side == SIDE_EAST_WEST) {
		map_x = (int)ray->vertical_x;
		map_y = (int)ray->vertical_y;
		if (ray->ray_dir_x < 0)
			map_x += 1;
	} else {
		map_x = (int)ray->horizontal_x;
		map_y = (int)ray->horizontal_y;
		if (ray->ray_dir_y > 0)
			map_y += 1;
	}
	if (map_y >= 0 && map_y < data->map_height && 
		map_x >= 0 && map_x < data->map_width &&
		data->map[map_y] && map_x < (int)ft_strlen(data->map[map_y]) &&
		data->map[map_y][map_x] == 'D') {
		door = get_door_at(data, map_x, map_y);
		if (door) {
			door_offset = (int)(door->open_progress * ray->line_height);
			ray->draw_start += door_offset;
			if (ray->draw_start >= ray->draw_end) {
				ray->draw_start = ray->draw_end;
			}
		}
	}
}

void	handle_rutils_bonus_features(t_data *data, t_ray *ray)
{
	apply_door_animation(data, ray);
}
#else

void	handle_rutils_bonus_features(t_data *data, t_ray *ray)
{
	(void) ray;
	(void) data;
}
#endif
