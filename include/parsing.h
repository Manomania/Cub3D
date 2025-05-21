/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:29:12 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/19 18:36:25 by elagouch         ###   ########.fr       */
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

bool	fill_map(t_data *data, int fd);

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

#endif
