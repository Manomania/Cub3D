/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:59:05 by maximart          #+#    #+#             */
/*   Updated: 2025/05/19 18:28:58 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_args(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
	{
		ft_printf_fd(2, RED "Usage: %s <map_file>\n" RESET, argv[0]);
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
