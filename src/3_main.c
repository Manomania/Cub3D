/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:06:00 by maximart          #+#    #+#             */
/*   Updated: 2025/05/09 16:08:07 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <limits.h>

static bool check_data(t_data *data)
{
	if (data->floor_color[0] < 0 || data->floor_color[0] > 255)
		return (true);
	if (data->floor_color[1] < 0 || data->floor_color[1] > 255)
		return (true);
	if (data->floor_color[1] < 0 || data->floor_color[1] > 255)
		return (true);
	if (data->ceil_color[0] < 0 || data->ceil_color[0] > 255)
		return (true);
	if (data->ceil_color[1] < 0 || data->ceil_color[1] > 255)
		return (true);
	if (data->ceil_color[1] < 0 || data->ceil_color[1] > 255)
		return (true);
	if (data->map_height <= 0 || data->map_width <= 0)
		return (true);
	return (false);
}

int	main(int argc, char **argv)
{
	t_data	*data = NULL;

	if (check_args(argc, argv))
		return (1);
	data = init_data();
	if (!data)
		free_ressources(data);
	if (read_file(data, argv[1]))
		free_ressources(data);
	if (check_data(data))
	{
		printf(RED"DEBUG: texture_north: %s\n"RESET, data->texture_n);
		printf(RED"DEBUG: texture_south: %s\n"RESET, data->texture_s);
		printf(RED"DEBUG: texture_west: %s\n"RESET, data->texture_w);
		printf(RED"DEBUG: texture_east: %s\n"RESET, data->texture_e);
		printf(RED"DEBUG: F color[r]: %d\n"RESET, data->floor_color[0]);
		printf(RED"DEBUG: F color[g]: %d\n"RESET, data->floor_color[1]);
		printf(RED"DEBUG: F color[b]: %d\n"RESET, data->floor_color[2]);
		printf(RED"DEBUG: C color[r]: %d\n"RESET, data->ceil_color[0]);
		printf(RED"DEBUG: C color[g]: %d\n"RESET, data->ceil_color[1]);
		printf(RED"DEBUG: C color[b]: %d\n"RESET, data->ceil_color[2]);
		printf(RED"DEBUG: HEIGHT: %d\n"RESET, data->map_height);
		printf(RED"DEBUG: WIDTH: %d\n"RESET, data->map_width);
		free_ressources(data);
	}
	int i = 0;
	while (i < data->map_height)
	{
		printf(YELLOW"DEBUG: map: %s"RESET, data->map[i]);
		i++;
	}
	printf(YELLOW"\nDEBUG: texture_north: %s\n"RESET, data->texture_n);
	printf(YELLOW"DEBUG: texture_south: %s\n"RESET, data->texture_s);
	printf(YELLOW"DEBUG: texture_west: %s\n"RESET, data->texture_w);
	printf(YELLOW"DEBUG: texture_east: %s\n"RESET, data->texture_e);
	printf(YELLOW"DEBUG: F color[r]: %d\n"RESET, data->floor_color[0]);
	printf(YELLOW"DEBUG: F color[g]: %d\n"RESET, data->floor_color[1]);
	printf(YELLOW"DEBUG: F color[b]: %d\n"RESET, data->floor_color[2]);
	printf(YELLOW"DEBUG: C color[r]: %d\n"RESET, data->ceil_color[0]);
	printf(YELLOW"DEBUG: C color[g]: %d\n"RESET, data->ceil_color[1]);
	printf(YELLOW"DEBUG: C color[b]: %d\n"RESET, data->ceil_color[2]);
	printf(YELLOW"DEBUG: HEIGHT: %d\n"RESET, data->map_height);
	printf(YELLOW"DEBUG: WIDTH: %d\n"RESET, data->map_width);
	free_ressources(data);
	return (0);
}
