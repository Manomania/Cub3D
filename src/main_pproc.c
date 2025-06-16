/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pproc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:01:13 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 19:17:14 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_bonus.h"

void	init_door_system(t_data *data);

#ifdef BONUS

void	handle_main_bonus_features(t_data *data)
{
	mouse_init(data->win_width, data->win_height);
	init_door_system(data);
}
#else

void	handle_main_bonus_features(t_data *data)
{
	(void)data;
}
#endif
