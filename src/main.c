/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:06:00 by maximart          #+#    #+#             */
/*   Updated: 2025/05/16 17:55:55 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <limits.h>

void	final_countdown(t_data *data)
{
	int	y;

	if (!data)
		return ;
	if (data->player)
	{
		free(data->player);
		data->player = NULL;
	}
	if (data->map)
	{
		y = -1;
		while (data->map[++y])
		{
			free(data->map[y]);
			data->map[y] = NULL;
		}
		free(data->map);
		data->map = NULL;
	}
	free(data);
}

char	**init_test_map(int height, int width)
{
	char	**map;
	int		y;
	int		x;
	int		tmp;

	map = ft_calloc(height, sizeof(char *));
	if (!map)
		return (NULL);
	y = -1;
	while (++y < height)
	{
		map[y] = ft_calloc(width, sizeof(char));
		if (!map[y])
		{
			tmp = -1;
			while (++tmp < y)
			{
				free(map[tmp]);
				map[tmp] = NULL;
			}
			free(map);
			return (NULL);
		}
		x = -1;
		while (++x < width)
			map[y][x] = '0';
		if (y == 0 || y == height - 1)
		{
			x = -1;
			while (++x < width)
				map[y][x] = '1';
		}
		else
		{
			map[y][0] = '1';
			map[y][width - 1] = '1';
		}
	}
	return (map);
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
	data->map_width = MAP_W;  // WARN !!!
	data->map_height = MAP_H; // WARN !!!
	data->player = ft_calloc(1, sizeof(t_player));
	if (!data->player)
	{
		free(data);
		return (NULL);
	}
	data->map = init_test_map(data->map_height, data->map_width);
	if (!data->map)
	{
		free(data->player);
		free(data);
		return (NULL);
	}
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
	final_countdown(data);
	return (0);
}
