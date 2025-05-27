/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:38:26 by maximart          #+#    #+#             */
/*   Updated: 2025/05/27 18:38:26 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "draw.h"

void	draw_border_lines(t_data *data, t_draw_params *params)
{
	params->x = params->minimap_x;
	params->y = params->minimap_y;
	params->width = params->minimap_x + MINIMAP_SIZE;
	params->height = params->minimap_y;
	draw_line(data, params);
	params->y = params->minimap_y + MINIMAP_SIZE;
	params->height = params->minimap_y + MINIMAP_SIZE;
	draw_line(data, params);
	params->width = params->minimap_x;
	params->height = params->minimap_y + MINIMAP_SIZE;
	draw_line(data, params);
	params->x = params->minimap_x + MINIMAP_SIZE;
	params->width = params->minimap_x + MINIMAP_SIZE;
	params->height = params->minimap_y + MINIMAP_SIZE;
	draw_line(data, params);
}

bool	check_fov_bounds(t_draw_params *params, int screen_x, int screen_y)
{
	if (screen_x < params->minimap_x
		|| screen_x >= params->minimap_x + MINIMAP_SIZE
		|| screen_y < params->minimap_y
		|| screen_y >= params->minimap_y + MINIMAP_SIZE)
		return (true);
	return (false);
}

bool	is_player_in_bounds(t_draw_params *params)
{
	if (params->x >= params->minimap_x && params->y >= params->minimap_y
		&& params->x + MINIMAP_PLAYER_SIZE <= params->minimap_x + MINIMAP_SIZE
		&& params->y + MINIMAP_PLAYER_SIZE <= params->minimap_y + MINIMAP_SIZE)
		return (true);
	return (false);
}

static void	draw_single_fov_line(t_data *data, t_draw_params *params,
		int *player_screen, int end_x, int end_y)
{
	params->x = player_screen[0];
	params->y = player_screen[1];
	params->width = end_x;
	params->height = end_y;
	draw_line(data, params);
}

void	draw_player_fov(t_data *data, t_draw_params *params, int *player_screen)
{
	double	player_angle;
	int		fov_ends[4];

	params->color.val = MINIMAP_FOV_COLOR;
	player_angle = atan2(data->player.dir_y, data->player.dir_x);
	cast_fov_ray(data, params, player_angle - 0.5);
	fov_ends[0] = params->end_x;
	fov_ends[1] = params->end_y;
	cast_fov_ray(data, params, player_angle + 0.5);
	fov_ends[2] = params->end_x;
	fov_ends[3] = params->end_y;
	cast_fov_ray(data, params, player_angle);
	draw_single_fov_line(data, params, player_screen, fov_ends[0], fov_ends[1]);
	draw_single_fov_line(data, params, player_screen, fov_ends[2], fov_ends[3]);
	draw_single_fov_line(data, params, player_screen, params->end_x,
		params->end_y);
}
