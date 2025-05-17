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

# include <stdbool.h>
# include "libft.h"
# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"

/*******************************************************************************
*                                    Macros                                    *
*******************************************************************************/

# define TITLE "cub3d"
# define RESET "\033[039m"
# define RED "\033[091m"
# define BLUE "\033[034m"
# define GREEN "\033[092m"
# define YELLOW "\033[093m"
# define CYAN "\033[36m"

/*******************************************************************************
*                                  Structures                                  *
*******************************************************************************/

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
	char	**map;
	int		map_x;
	int		map_y;
	char	*adrr;
	char	*texture_n;
	char	*texture_s;
	char	*texture_w;
	char	*texture_e;
	int		floor_color[3];
	int		ceil_color[3];
	int		bits_per_pixel;
	int		map_height;
	int		map_width;
	int		line_length;
	int		endian;
	int		win_height;
	int		win_width;
	void	*mlx;
	void	*win;
}			t_data;

/*******************************************************************************
*                             Function Prototypes                              *
*******************************************************************************/

// color_parser.c
bool	parse_color_line(t_data *data, char *line, const char *id);

// file_parser.c
int		read_file(t_data *data, const char *file);

// main.c

// map_parser.c
bool	process_map(t_data	*data, char *line);

// texture_parser.c
bool	parse_texture_path(t_data *data, char *line, const char *cardinal);

// utils.c
bool	check_args(int argc, char **argv);
t_data	*init_data(void);
void	free_ressources(t_data *data);
#endif
