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

bool	check_error(int argc, char **argv)
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

t_data *init_data()
{
	t_data *data;
	data = ft_calloc(1, sizeof(t_data));
	return (data);
}

int	main (int argc, char **argv)
{
	t_data	*data;

	if (check_error(argc, argv))
		return (1);
	data = init_data();
	if (!data)
	{
		//TODO error msg
		return (1);
	}
	if (read_file(data, argv[1]))
	return (0);
}