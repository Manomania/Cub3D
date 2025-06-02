/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:47:51 by maximart          #+#    #+#             */
/*   Updated: 2025/06/02 13:48:12 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include "cub3d.h"

/*******************************************************************************
 *                                    Macros                                   *
 ******************************************************************************/

# define MOUSE_SENSITIVITY 0.002
# define MOUSE_MIN 0.0005
# define MOUSE_MAX 0.01
# define MOUSE_LEFT_CLICK 1
# define MOUSE_RIGHT_CLICK 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

/*******************************************************************************
 *                                  Structures                                 *
 ******************************************************************************/

typedef struct s_mouse
{
	int		x;
	int		y;
	int		last_x;
	int		last_y;
	bool	is_active;
	bool	first_move;
	double	sensitivity;
}	t_mouse;

/*******************************************************************************
 *                             Function Prototypes                             *
 ******************************************************************************/

void	mouse_toggle(void);
void	mouse_init(int win_width, int win_height);
void	mouse_setup_hooks(t_data *data);

#endif
