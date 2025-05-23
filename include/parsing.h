/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:29:12 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/21 16:35:35 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

/*
** p_color.c
*/

/**
 * @brief Parse a line that defines a color
 *
 * @param data
 * @param line
 * @param id
 * @return true
 * @return false
 */
bool	parse_color_line(t_data *data, char *line, const char *id);

/*
** p_color_utils.c
*/

/**
 * @brief Check the line if it is not digit
 *
 * @param data
 * @param color
 * @return true
 * @return false
 */
bool	check_color_line(t_data *data, char *color);

/**
 * @brief Check rgb if its between 0 and 255
 *
 * @param data
 * @param r
 * @param g
 * @param b
 * @return true
 * @return false
 */
bool	check_rgb_range(t_data *data, int r, int g, int b);

/*
** p_file.c
*/

/**
 * @brief Open and parses a file
 *
 * @param data App data
 * @param file File to open
 * @return int 1 on failure, 0 otherwise
 */
int		read_file(t_data *data, const char *file);

/*
** p_map.c
*/

/**
 * @brief Process the dimentions of a map from a line
 *
 * @param data App data
 * @param line Line to process
 * @return false Always return false for some reason
 *
 * @note This function always return false for some reason. @maximart
 */
bool	process_map_dimension(t_data *data, char *line);

/**
 * @brief Comprehensive map validation using flood fill algorithm
 *
 * @param data App data containing the map to validate
 * @return true if map validation fails, false if map is valid
 */
bool	fill_map(t_data *data, int fd);

/*
** p_map_check.c
*/

/**
 * @brief Comprehensive map validation using flood fill algorithm
 *
 * @param data App data containing the map to validate
 * @return true if map validation fails, false if map is valid
 */
bool	check_map_validity(t_data *data);

/**
 * @brief Recursively performs flood fill algorithm on a 2D character map.
 *
 * @param map_copy 2D character array (map copy to avoid modifying original)
 * @param x Starting x-coordinate (column)
 * @param y Starting y-coordinate (row)
 * @param data Additional data structure for flood fill parameters
 * @return true if successful, false on error or invalid coordinates
 */
bool	flood_fill_recursive(char **map_copy, int x, int y, t_data *data);

/*
** p_map_copy.c
*/

/**
 * @brief Creating a copy of the map for checking
 *
 * @param data App data containing the map to copy
 * @return true if creating map failed, false if map is created
 */
char	**create_map_copy(t_data *data);


/**
 * @brief Check the line is it contains the char needed
 *
 * @param line Line to process
 * @return true if line is unvalid, false if map is valid
 */
bool	is_map_line_valid(char *line);

/*
** p_texture.c
*/

/**
 * @brief Parses a texture path from a line
 *
 * @param data App data
 * @param line Line to parse
 * @param cardinal Cardinal direction
 * @return true On error
 * @return false On success
 */
bool	parse_texture_path(t_data *data, char *line, const char *cardinal);

/*
** p_validation.c
*/

/**
 * @brief Validate that all required configuration is present
 *
 * @param data App data structure to validate
 * @return true if configuration is incomplete, false if complete
 */
bool	validate_config_completeness(t_data *data);

/**
 * @brief Check if all texture paths are properly set
 *
 * @param data App data structure
 * @return true if textures missing, false if all present
 */
bool	check_texture_completeness(t_data *data);

/**
 * @brief Check if colors are properly configured
 *
 * @param data App data structure
 * @return true if colors missing, false if properly set
 */
bool	check_color_completeness(t_data *data);

#endif
