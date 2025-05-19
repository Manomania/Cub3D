/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_shadow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:13:47 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/19 18:52:34 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_color	apply_shadow(t_color color, int side)
{
	t_color	c;

	c = color;
	if (side == 1)
	{
		c.red /= 2;
		c.green /= 2;
		c.blue /= 2;
	}
	return (c);
}
