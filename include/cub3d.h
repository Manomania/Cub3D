/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:05:19 by maximart          #+#    #+#             */
/*   Updated: 2025/05/16 19:03:42 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3d_H
# define cub3d_H

# include "libft.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

// *************************************************************************** #
//                                   Macros                                    #
// *************************************************************************** #

# define RESET "\033[039m"
# define RED "\033[091m"
# define BLUE "\033[034m"
# define GREEN "\033[092m"
# define YELLOW "\033[093m"
# define CYAN "\033[36m"

# define MAP_W 24
# define MAP_H 17

# define WIN_H 600
# define WIN_W 800

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
}				t_keyboard;

typedef enum e_key
{
	ON_DESTROY = 17,
}				t_key;

/*
** Raycasting implementation using DDA algorithm
** This is the core of the 3D rendering engine for cub3d
*/

typedef struct s_ray
{
	// Components of ray direction vector
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	// Step dirs are -1 or 1
	int			step_x;
	int			step_y;
	// Flag
	bool		hit;
	// Which side was hit
	int			side;
	int			line_height;
	// Start and end Y positions
	int			draw_start;
	int			draw_end;
}				t_ray;

/*
** Player structure to handle position, direction, and movement
*/
typedef struct s_player
{
	/* Position */
	double		pos_x;
	double		pos_y;

	/* Direction */
	double dir_x; // X component of direction vector (where player is looking)
	double dir_y; // Y component of direction vector

	/* Camera plane */
	double plane_x; // X component of camera plane (perpendicular to direction)
	double plane_y; // Y component of camera plane

	/* Movement */
	double move_speed; // Movement speed (can be adjusted for frame time)
	double rot_speed;  // Rotation speed (can be adjusted for frame time)

	/* Controls state */
	int move_forward;  // Flag for moving forward (W key)
	int move_backward; // Flag for moving backward (S key)
	int move_left;     // Flag for moving left (A key)
	int move_right;    // Flag for moving right (D key)
	int rotate_left;   // Flag for rotating left (left arrow)
	int rotate_right;  // Flag for rotating right (right arrow)

	/* Screen properties */
	double cam_height; // Camera height (usually screen_height/2)
}				t_player;

/*
** Texture structure to store image data
*/
typedef struct s_texture
{
	void *img;          // MLX image pointer
	char *addr;         // Image data address
	int width;          // Texture width
	int height;         // Texture height
	int bits_per_pixel; // Bits per pixel
	int line_length;    // Line length
	int endian;         // Endian format
}				t_texture;

/*
** Structure to hold all textures
*/
typedef struct s_textures
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
}				t_textures;

/*
** Image structure for MLX
**
** Most of the info you would stick in the data struct normally are actually
** stored here for convenience
*/
typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

/*
** Global application data
*/
typedef struct s_data
{
	// Whole map
	char		**map;
	// Textures
	char		*texture_n;
	char		*texture_s;
	char		*texture_e;
	char		*texture_w;
	// MLX stuff
	t_img		img;
	void		*mlx;
	void		*win;
	// Sizes
	int			map_height;
	int			map_width;
	int			win_width;
	int			win_height;
	// Pointers
	t_player	player;
	t_textures	textures;
	// Colors
	// TODO: Change these to a union type
	int			floor_color;
	int			ceil_color;
}				t_data;

// *************************************************************************** #
//                            Function Prototypes                              #
// *************************************************************************** #

/**
 * @brief Renders a frame. Duh.
 *
 * @param data App data
 */
void			render_frame(t_data *data);

#endif
