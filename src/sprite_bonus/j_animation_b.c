/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_animation_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:40:20 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/20 18:38:52 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "sprite_bonus.h"
#include "utils.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

bool	load_sprite_textures(t_data *data, t_sprite *sprite)
{
	char	*base_path;
	char	*extension;
	char	*frame_path;
	char	*resolved_path;
	int		frame;
	char	frame_suffix[10];
	int		valid_frames = 0;

	if (!data->texture_sprite)
		return (false);
	sprite->animation.frame_count = 0;
	sprite->animation.frame_duration = 0.5f;
	sprite->animation.current_time = 0.0f;
	sprite->animation.current_frame = 0;
	sprite->animation.loop = true;
	base_path = ft_strdup(data->texture_sprite);
	extension = ft_strrchr(base_path, '.');
	if (extension)
		*extension = '\0';
	frame = 1;
	while (frame <= MAX_SPRITE_FRAMES && valid_frames < MAX_SPRITE_FRAMES)
	{
		snprintf(frame_suffix, sizeof(frame_suffix), "_%02d.xpm", frame);
		frame_path = ft_strjoin(base_path, frame_suffix);
		if (!frame_path)
			break;
		resolved_path = resolve_path(data->map_file_path, frame_path);
		free(frame_path);
		if (!resolved_path)
		{
			frame++;
			continue;
		}
		sprite->animation.frames[valid_frames].img = 
			mlx_xpm_file_to_image(data->mlx, resolved_path,
				&sprite->animation.frames[valid_frames].width,
				&sprite->animation.frames[valid_frames].height);
		if (!sprite->animation.frames[valid_frames].img)
		{
			free(resolved_path);
			frame++;
			continue;
		}
		sprite->animation.frames[valid_frames].addr = 
			mlx_get_data_addr(sprite->animation.frames[valid_frames].img,
				&sprite->animation.frames[valid_frames].bits_per_pixel,
				&sprite->animation.frames[valid_frames].line_length,
				&sprite->animation.frames[valid_frames].endian);
		valid_frames++;
		free(resolved_path);
		frame++;
	}
	sprite->animation.frame_count = valid_frames;
	free(base_path);
	if (sprite->animation.frame_count == 0)
	{
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
		sprite->animation.frame_count = 1;
	}
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