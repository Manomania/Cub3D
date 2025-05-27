
#ifndef MINIMAP_H
#define MINIMAP_H

# include "cub3d.h"


/*******************************************************************************
 *                                    Macros                                   *
 ******************************************************************************/

# define MINIMAP_SIZE 200
# define MINIMAP_MARGIN 50
# define MINIMAP_SCALE 20
# define MINIMAP_PLAYER_SIZE 3
# define MINIMAP_FOV_LENGTH 200
# define MINIMAP_WALL_COLOR 0xFFFFFF
# define MINIMAP_PLAYER_COLOR 0xFF0000
# define MINIMAP_FOV_COLOR 0x00FF00
# define MINIMAP_BORDER_COLOR 0x808080

/*******************************************************************************
 *                                  Structures                                 *
 ******************************************************************************/

typedef struct s_draw_params
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		minimap_x;
	int		minimap_y;
	int		cell_size;
	int		center_x;
	int		center_y;
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	t_color	color;
}	t_draw_params;

/*******************************************************************************
 *                             Function Prototypes                             *
 ******************************************************************************/

/*
** n_minimap.c
*/

/**
 * @brief Draws the complete minimap on screen
 *
 * @param data Main game data structure containing player and map info
 */
void	draw_minimap(t_data *data);

/**
 * @brief Draws a filled rectangle with specified parameters
 *
 * @param data Main game data structure for screen dimensions
 * @param params Drawing parameters including position, size, and color
 */
void	draw_filled_rect(t_data *data, t_draw_params *params);

/*
** n_draw.c
*/

/**
 * @brief Clamps rectangle bounds to fit within screen dimensions
 *
 * @param data Main game data structure containing screen dimensions
 * @param params Drawing parameters to be clamped (modified in place)
 */
void	clamp_rect_bounds(t_data *data, t_draw_params *params);

/**
 * @brief Draws a line between two points using Bresenham's algorithm
 *
 * @param data Main game data structure for screen access
 * @param params Line parameters (start/end points and color)
 */
void	draw_line(t_data *data, t_draw_params *params);

/**
 * @brief Draws the border frame around the minimap
 *
 * @param data Main game data structure
 * @param params Drawing parameters for border positioning
 */
void	draw_minimap_border(t_data *data, t_draw_params *params);

/*
** n_grid.c
*/

/**
 * @brief Renders the map grid/cells on the minimap
 *
 * @param data Main game data containing the map array
 * @param params Drawing parameters for grid positioning and scaling
 */
void	draw_minimap_grid(t_data *data, t_draw_params *params);

/*
** n_player.c
*/

/**
 * @brief Casts a single ray for field of view calculation
 *
 * @param data Main game data with player position and map
 * @param params Drawing parameters, end coordinates stored in end_x/end_y
 * @param angle Ray direction in radians
 */
void	cast_fov_ray(t_data *data, t_draw_params *params, double angle);

/**
 * @brief Draws the player representation on the minimap
 *
 * @param data Main game data with player information
 * @param params Drawing parameters for player visualization
 */
void	draw_minimap_player(t_data *data, t_draw_params *params);

/*
** n_utils.c
*/

/**
 * @brief Draws the four border lines around minimap perimeter
 *
 * @param data Main game data structure
 * @param params Drawing parameters with border positioning
 */
void	draw_border_lines(t_data *data, t_draw_params *params);

/**
 * @brief Checks if screen coordinates are within minimap FOV bounds
 *
 * @param params Drawing parameters containing minimap boundaries
 * @param screen_x X coordinate to check
 * @param screen_y Y coordinate to check
 * @return true if coordinates are outside bounds, false if within
 */
bool	check_fov_bounds(t_draw_params *params, int screen_x, int screen_y);

/**
 * @brief Checks if player sprite fits within minimap boundaries
 *
 * @param params Drawing parameters with player position and minimap bounds
 * @return true if player fits within bounds, false otherwise
 */
bool	is_player_in_bounds(t_draw_params *params);

/**
 * @brief Draws the player's field of view cone on minimap
 *
 * @param data Main game data with player direction information
 * @param params Drawing parameters for FOV visualization
 * @param player_screen Array with player screen position [x, y]
 */
void	draw_player_fov(t_data *data, t_draw_params *params, int *player_screen);

#endif
