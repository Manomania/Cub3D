/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_animation_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:40:20 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/20 15:31:21 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "sprite_bonus.h"
#include "utils.h"
#include "mlx.h"
#include <stdlib.h>

bool	load_sprite_textures(t_data *data, t_sprite *sprite)
{
	char	*resolved_path;

	if (!data->texture_sprite)
		return (false);
		
	sprite->animation.frame_count = 1;
	sprite->animation.frame_duration = 1.0f;
	sprite->animation.current_time = 0.0f;
	sprite->animation.current_frame = 0;
	sprite->animation.loop = true;

	resolved_path = resolve_path(data->map_file_path, data->texture_sprite);
	if (!resolved_path)
		return (false);
		
	sprite->animation.frames[0].img = mlx_xpm_file_to_image(data->mlx,
			resolved_path, &sprite->animation.frames[0].width,
			&sprite->animation.frames[0].height);
	free(resolved_path);
	
	if (!sprite->animation.frames[0].img)
		return (false);
		
	sprite->animation.frames[0].addr = mlx_get_data_addr(
			sprite->animation.frames[0].img,
			&sprite->animation.frames[0].bits_per_pixel,
			&sprite->animation.frames[0].line_length,
			&sprite->animation.frames[0].endian);
	return (true);
}


void	update_sprite_animation(t_sprite *sprite, double delta_time)
{
	if (sprite->animation.frame_count <= 1)
		return ;
	sprite->animation.current_time += delta_time;
	if (sprite->animation.current_time >= sprite->animation.frame_duration)
	{
		sprite->animation.current_time = 0.0f;
		sprite->animation.current_frame++;
		if (sprite->animation.current_frame >= sprite->animation.frame_count)
		{
			if (sprite->animation.loop)
				sprite->animation.current_frame = 0;
			else
				sprite->animation.current_frame = sprite->animation.frame_count - 1;
		}
	}
}