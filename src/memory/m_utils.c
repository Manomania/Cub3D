/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:59:05 by maximart          #+#    #+#             */
/*   Updated: 2025/05/16 17:59:05 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_args(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
	{
		ft_printf_fd(2, RED"Usage: %s <map_file>\n"RESET, argv[0]);
		return (true);
	}
	else
	{
		len = ft_strlen(argv[1]);
		if (len < 4 || ft_strcmp(&argv[1][len - 4], ".cub") != 0)
		{
			ft_printf("%sError:\nInvalid extension\n%s", RED, RESET);
			return (true);
		}
	}
	return (false);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	data->floor_color[0] = -1;
	data->floor_color[1] = -1;
	data->floor_color[2] = -1;
	data->ceil_color[0] = -1;
	data->ceil_color[1] = -1;
	data->ceil_color[2] = -1;
	return (data);
}

bool	init_map_array(t_data *data)
{
	data->map = ft_calloc(data->map_height + 1,
			sizeof(char *) * data->map_height + 1);
	if (!data->map)
		return (true);
	return (false);
}

void	free_ressources(t_data *data)
{
	if (!data)
		return ;
	free_map(data);
	if (data->texture_n)
		free(data->texture_n);
	if (data->texture_s)
		free(data->texture_s);
	if (data->texture_w)
		free(data->texture_w);
	if (data->texture_e)
		free(data->texture_e);
	free(data);
	exit(1);
}

void	free_map(t_data *data)
{
	int	i;

	if (!data->map)
		return ;
	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
}
