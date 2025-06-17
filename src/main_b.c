/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:01:13 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/17 14:05:55 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "pproc.h"
#include "mouse_bonus.h"
#include "door_bonus.h"

void	handle_main_bonus_features(t_data *data)
{
	mouse_init(data->win_width, data->win_height);
	init_door_system(data);
}
