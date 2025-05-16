/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:06:00 by maximart          #+#    #+#             */
/*   Updated: 2025/05/16 19:03:42 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include "player.h"
#include <limits.h>

int		generate_dummy_textures(t_data *data);
int		generate_dummy_map(t_data *data);

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	*free_data(t_data *data)
{
	if (!data)
		return (NULL);
	if (data->map)
	{
		free_map(data->map);
		data->map = NULL;
	}
	if (data->textures.north.img)
		mlx_destroy_image(data->mlx, data->textures.north.img);
	if (data->textures.south.img)
		mlx_destroy_image(data->mlx, data->textures.south.img);
	if (data->textures.east.img)
		mlx_destroy_image(data->mlx, data->textures.east.img);
	if (data->textures.west.img)
		mlx_destroy_image(data->mlx, data->textures.west.img);
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	return (NULL);
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

t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_data(data));
	data->win_width = WIN_W;      // WARN !!!
	data->win_height = WIN_H;     // WARN !!!
	data->map_width = MAP_W;      // WARN !!!
	data->map_height = MAP_H;     // WARN !!!
	data->floor_color = 0x555555; // WARN !!!
	data->ceil_color = 0xAAAAAA;  // WARN !!!
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"cub3d");
	if (!data->win)
		return (free_data(data));
	data->img.img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	// TODO: Actual map loading
	generate_dummy_map(data);
	if (!data->map)
		return (free_data(data));
	// TODO: Actual textures loading
	generate_dummy_textures(data);
	display_map(data);
	return (data);
}

bool	check_error(int argc, char **argv)
{
	const char	*ptr;

	if (argc != 2)
	{
		ft_printf_fd(2, RED "Usage: %s <map_file>\n" RESET, argv[0]);
		return (true);
	}
	else
	{
		ptr = ft_strnstr(argv[1], ".cub", INT_MAX);
		if (!ptr || ptr[4] != '\0')
		{
			ft_printf("%sError:\nInvalid extension\n%s", RED, RESET);
			return (true);
		}
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_error(argc, argv))
		return (1);
	data = init_data();
	init_player(data);
	mlx_loop_hook(data->mlx, (int (*)())render_frame, data);
	mlx_loop(data->mlx);
	data = free_data(data);
	ft_printf("########################### END! ###########################\n");
	return (0);
}
