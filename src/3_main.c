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

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_args(argc, argv))
		return (1);
	data = init_data();
	if (!data)
		free_ressources(data);
	if (read_file(data, argv[1]))
		free_ressources(data);
	// printf(YELLOW"\nDEBUG: texture_north: %s\n"RESET, data->texture_n);
	// printf(YELLOW"DEBUG: texture_south: %s\n"RESET, data->texture_s);
	// printf(YELLOW"DEBUG: texture_west: %s\n"RESET, data->texture_w);
	// printf(YELLOW"DEBUG: texture_east: %s\n"RESET, data->texture_e);
	// printf(YELLOW"DEBUG: F color[r]: %d\n"RESET, data->floor_color[0]);
	// printf(YELLOW"DEBUG: F color[g]: %d\n"RESET, data->floor_color[1]);
	// printf(YELLOW"DEBUG: F color[b]: %d\n"RESET, data->floor_color[2]);
	// printf(YELLOW"DEBUG: C color[r]: %d\n"RESET, data->ceil_color[0]);
	// printf(YELLOW"DEBUG: C color[g]: %d\n"RESET, data->ceil_color[1]);
	// printf(YELLOW"DEBUG: C color[b]: %d\n"RESET, data->ceil_color[2]);
	// printf(YELLOW"DEBUG: HEIGHT: %d\n"RESET, data->map_height);
	// printf(YELLOW"DEBUG: WIDTH: %d\n"RESET, data->map_width);
	free_ressources(data);
	return (0);
}
