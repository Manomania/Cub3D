/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:06:00 by maximart          #+#    #+#             */
/*   Updated: 2025/05/23 13:41:52 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mem.h"
#include "mlx.h"
#include "parsing.h"
#include "player.h"
#include "utils.h"
#include <limits.h>

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
	// data->map_width = MAP_W;
	// data->map_height = MAP_H;
	// data->floor_color.val = 0x555555;
	// data->ceil_color.val = 0xAAAAAA;
}

t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->error_detected = false;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_ressource(data));
	this_will_be_removed_eventually(data);
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"cub3d");
	if (!data->win)
		return (free_ressource(data));
	data->img.img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	display_map(data);
	init_fps(data);
	return (data);
}

bool	check_error(int argc, char **argv)
{
	const char	*ptr;

	if (argc != 2)
	{
		ft_printf_fd(2, RED "Error\nUsage: %s <map_file>\n" RESET, argv[0]);
		return (true);
	}
	else
	{
		ptr = ft_strnstr(argv[1], ".cub", INT_MAX);
		if (!ptr || ptr[4] != '\0')
		{
			ft_printf(RED "Error\nInvalid extension\n" RESET);
			return (true);
		}
	}
	return (false);
}

static bool	check_map(t_data *data)
{
	if (check_map_validity(data))
		return (true);
	// if (data->map_height <= 0 || data->map_width <= 0 || !data->map)
	// 	return (true);
	return (false);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	if (check_error(argc, argv))
		return (1);
	data = init_data();
	if (!data)
	{
		free_ressource(data);
		return (1);
	}
	data->map_file_path = ft_strdup(argv[1]);
	if (!data->map_file_path)
	{
		free_ressource(data);
		return (1);
	}
	if (read_file(data, argv[1]) || data->error_detected)
	{
		free_ressource(data);
		return (1);
	}
	if (check_map(data))
	{
		printf(RED "DEBUG: texture_north: %s\n" RESET, data->texture_n);
		printf(RED "DEBUG: texture_south: %s\n" RESET, data->texture_s);
		printf(RED "DEBUG: texture_west: %s\n" RESET, data->texture_w);
		printf(RED "DEBUG: texture_east: %s\n" RESET, data->texture_e);
		printf(RED "DEBUG: F color[r]: %d\n" RESET, data->floor_color.red);
		printf(RED "DEBUG: F color[g]: %d\n" RESET, data->floor_color.green);
		printf(RED "DEBUG: F color[b]: %d\n" RESET, data->floor_color.blue);
		printf(RED "DEBUG: C color[r]: %d\n" RESET, data->ceil_color.red);
		printf(RED "DEBUG: C color[g]: %d\n" RESET, data->ceil_color.green);
		printf(RED "DEBUG: C color[b]: %d\n" RESET, data->ceil_color.blue);
		printf(RED "DEBUG: HEIGHT: %d\n" RESET, data->map_height);
		printf(RED "DEBUG: WIDTH: %d\n" RESET, data->map_width);
		free_ressource(data);
		return (1);
	}
	i = 0;
	if (data && data->map)
	{
		while (i < data->map_height && data->map[i])
		{
			printf(YELLOW "DEBUG: map: %s" RESET, data->map[i]);
			i++;
		}
	}
	printf(YELLOW "\nDEBUG: texture_north: %s\n" RESET, data->texture_n);
	printf(YELLOW "DEBUG: texture_south: %s\n" RESET, data->texture_s);
	printf(YELLOW "DEBUG: texture_west: %s\n" RESET, data->texture_w);
	printf(YELLOW "DEBUG: texture_east: %s\n" RESET, data->texture_e);
	printf(YELLOW "DEBUG: F color[r]: %d\n" RESET, data->floor_color.red);
	printf(YELLOW "DEBUG: F color[g]: %d\n" RESET, data->floor_color.green);
	printf(YELLOW "DEBUG: F color[b]: %d\n" RESET, data->floor_color.blue);
	printf(YELLOW "DEBUG: C color[r]: %d\n" RESET, data->ceil_color.red);
	printf(YELLOW "DEBUG: C color[g]: %d\n" RESET, data->ceil_color.green);
	printf(YELLOW "DEBUG: C color[b]: %d\n" RESET, data->ceil_color.blue);
	printf(YELLOW "DEBUG: HEIGHT: %d\n" RESET, data->map_height);
	printf(YELLOW "DEBUG: WIDTH: %d\n" RESET, data->map_width);
	if (load_game_textures(data))
	{
		free_ressource(data);
		return (1);
	}
	init_player(data);
	setup_mlx_hooks(data);
	mlx_loop(data->mlx);
	free_ressource(data);
	ft_printf("########################### END! ###########################\n");
	return (0);
}
