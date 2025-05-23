/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_math.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:04:42 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/23 14:03:32 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

double	calculate_wall_hit(t_data *data, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = data->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = data->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

int	calculate_texture_x(double wall_x, t_texture *texture, t_ray *ray)
{
	int	tex_x;

	tex_x = (int)(wall_x * (double)texture->width);
	if ((ray->side == 0 && ray->ray_dir_x < 0) || (ray->side == 1
			&& ray->ray_dir_y > 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}
