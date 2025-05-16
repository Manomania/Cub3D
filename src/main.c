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

#include "cube3d.h"
#include <limits.h>

bool	check_error(int argc, char **argv)
{
	const char	*ptr;

	if (argc != 2)
	{
		ft_printf_fd(2, RED"Usage: %s <map_file>\n"RESET, argv[0]);
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

int	main (int argc, char **argv)
{
	if (check_error(argc, argv))
		return (1);
	return (0);
}