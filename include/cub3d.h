/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:05:19 by maximart          #+#    #+#             */
/*   Updated: 2025/05/16 17:53:33 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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

# define MAP_W 10
# define MAP_H 10

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
** This is the core of the 3D rendering engine for cub3D
*/

typedef struct s_ray
{
	double ray_dir_x;      // X component of ray direction vector
	double ray_dir_y;      // Y component of ray direction vector
	int map_x;             // Current map cell X position
	int map_y;             // Current map cell Y position
	double side_dist_x;    // Distance to next X side
	double side_dist_y;    // Distance to next Y side
	double delta_dist_x;   // Distance between X sides
	double delta_dist_y;   // Distance between Y sides
	double perp_wall_dist; // Perpendicular wall distance
	int step_x;            // X step direction (-1 or 1)
	int step_y;            // Y step direction (-1 or 1)
	int hit;               // Flag if a wall was hit
	int side;              // Which side was hit (NS or EW)
	int line_height;       // Height of wall line to draw
	int draw_start;        // Start y position to draw wall
	int draw_end;          // End y position to draw wall
}				t_ray;

/*
** Player structure to handle position, direction, and movement
*/
typedef struct s_player
{
	/* Position */
	double pos_x; // Player x position on the map
	double pos_y; // Player y position on the map

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
** Global application data
*/
typedef struct s_data
{
	char		**map;
	char		*adrr;
	char		*texture_n;
	char		*texture_s;
	char		*texture_e;
	char		*texture_w;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			map_height;
	int			map_width;
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	void		*img;
	t_player	*player;
	t_textures	*textures;
	// TODO: Change these to a union type
	char		floor_color;
	char		ceil_color;
}				t_data;

// *************************************************************************** #
//                            Function Prototypes                              #
// *************************************************************************** #

/**
 * @brief Initializes the player structure from app state
 *
 * @param data App state
 *
 * @note There are no checks for empty data struct, so passing a NULL *will*
 *       segfault.
 */
void			init_player(t_data *data);

#endif
