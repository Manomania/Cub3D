/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pproc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:01:13 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 14:46:52 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file is for the conditional preprocessor statements that mess with the
** norm, as indicated by the `pproc` suffix.
*/

#include "cub3d.h"
#include "cub3d_bonus.h"

#ifdef BONUS

void	handle_main_bonus_features(t_data *data)
{
	mouse_init(data->win_width, data->win_height);
}
#else

void	handle_main_bonus_features(t_data *data)
{
	(void)data;
}
#endif
