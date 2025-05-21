/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:06:00 by maximart          #+#    #+#             */
/*   Updated: 2025/05/20 19:49:34 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mem.h"
#include "mlx.h"
#include "parsing.h"
#include "player.h"
#include <limits.h>

int			generate_dummy_textures(t_data *data);
int			generate_dummy_map(t_data *data);

/*
** Initialize frame timing variables
*/
static void	init_fps(t_data *data)
{
	gettimeofday(&data->last_frame, NULL);
	data->fps = 0.0;
	data->frame_count = 0;
	data->fps_timer = 0.0;
}

void	display_map(t_data *data)
{
	int	x;
	int	y;

	if (!data->map)
		return ;
	y = -1;
	while (++y < data->map_height)
	{
		x = -1;
		while (++x < data->map_width)
			ft_putchar(data->map[y][x]);
		ft_putchar('\n');
	}
}

/*
** (¬,‿,¬)
*/
static void	this_will_be_removed_eventually(t_data *data)
{
	data->win_width = WIN_W;
	data->win_height = WIN_H;
	data->map_width = MAP_W;
	data->map_height = MAP_H;
	data->floor_color.val = 0x555555;
	data->ceil_color.val = 0xAAAAAA;
}

t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_data(data));
	this_will_be_removed_eventually(data);
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"cub3d");
	if (!data->win)
		return (free_data(data));
	data->img.img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	generate_dummy_textures(data);
	init_fps(data);
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_args(argc, argv))
		return (STDERR_FILENO);
	data = init_data();
	generate_dummy_map(data);
	// if (read_file(data, argv[1]))
	// 	free_data(data);
	display_map(data);
	init_player(data);
	setup_mlx_hooks(data);
	mlx_loop(data->mlx);
	data = free_data(data);
	return (0);
}
