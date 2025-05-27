/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_draw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:37:19 by maximart          #+#    #+#             */
/*   Updated: 2025/05/27 18:37:19 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "draw.h"

void	clamp_rect_bounds(t_data *data, t_draw_params *params)
{
	if (params->x + params->width > data->win_width)
		params->width = data->win_width - params->x;
	if (params->y + params->height > data->win_height)
		params->height = data->win_height - params->y;
}

static void	init_line_params(t_draw_params *params, int *dx, int *dy,
		int *step)
{
	*dx = abs(params->width - params->x);
	*dy = abs(params->height - params->y);
	if (params->x < params->width)
		step[0] = 1;
	else
		step[0] = -1;
	if (params->y < params->height)
		step[1] = 1;
	else
		step[1] = -1;
	params->start_x = *dx - *dy;
}

static void	draw_line_pixels(t_data *data, t_draw_params *params,
		int dx, int dy, int *step)
{
	int	err2;

	while (1)
	{
		if (params->x >= 0 && params->y >= 0
			&& params->x < data->win_width && params->y < data->win_height)
			my_mlx_pixel_put(&data->img, params->x, params->y, params->color);
		if (params->x == params->width && params->y == params->height)
			break ;
		err2 = 2 * params->start_x;
		if (err2 > -dy)
		{
			params->start_x -= dy;
			params->x += step[0];
		}
		if (err2 < dx)
		{
			params->start_x += dx;
			params->y += step[1];
		}
	}
}

void	draw_line(t_data *data, t_draw_params *params)
{
	int	dx;
	int	dy;
	int	step[2];

	init_line_params(params, &dx, &dy, step);
	draw_line_pixels(data, params, dx, dy, step);
}

void	draw_minimap_border(t_data *data, t_draw_params *params)
{
	params->color.val = MINIMAP_BORDER_COLOR;
	draw_border_lines(data, params);
}
