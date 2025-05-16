/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:05:19 by maximart          #+#    #+#             */
/*   Updated: 2025/05/16 11:48:10 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "libft.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/include/libft.h"
# include <stdbool.h>

// *************************************************************************** #
//                                   Macros                                    #
// *************************************************************************** #

# define TITLE "cub3d"
# define RESET "\033[039m"
# define RED "\033[091m"
# define BLUE "\033[034m"
# define GREEN "\033[092m"
# define YELLOW "\033[093m"
# define CYAN "\033[36m"

// *************************************************************************** #
//                                 Structures                                  #
// *************************************************************************** #

typedef enum e_keyboard
{
	ESCAPE = 65307,
	W = 119,
	S = 115,
	A = 100,
	D = 97,
}	t_keyboard;

typedef enum e_key
{
	ON_DESTROY = 17,
}	t_key;

typedef struct s_data
{
	char	**grid;
	char	*adrr;
	char	*texture_n;
	char	*texture_s;
	char	*texture_w;
	char	*texture_e;
	char	*floor_color;
	char	*ceil_color;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		win_height;
	int		win_width;
	void	*mlx;
	void	*win;
}			t_data;

#endif
