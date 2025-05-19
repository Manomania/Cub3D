/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_shadow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:13:47 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/19 16:36:14 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

/*
** TODO: different color handling with union type here as well
*/
unsigned int	apply_shadow(unsigned int color, int side)
{
	if (side == 1)
		return ((color >> 1) & 8355711);
	return (color);
}
