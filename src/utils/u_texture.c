/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_texture.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:39:02 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/23 13:42:30 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "texture.h"
#include "utils.h"

/**
 * @brief Resolve all texture paths relative to the map file
 *
 * @param data App data containing texture paths
 * @param map_path Path to the .cub map file
 * @return char** Array of resolved paths [N, E, S, W], or NULL on failure
 */
static char	**resolve_texture_paths(t_data *data, const char *map_path)
{
	char	**resolved_paths;
	char	*paths[4];

	paths[0] = data->texture_n;
	paths[1] = data->texture_e;
	paths[2] = data->texture_s;
	paths[3] = data->texture_w;
	resolved_paths = ft_calloc(5, sizeof(char *));
	if (!resolved_paths)
		return (NULL);
	resolved_paths[0] = resolve_path(map_path, paths[0]);
	resolved_paths[1] = resolve_path(map_path, paths[1]);
	resolved_paths[2] = resolve_path(map_path, paths[2]);
	resolved_paths[3] = resolve_path(map_path, paths[3]);
	return (resolved_paths);
}

/**
 * @brief Check if all texture files exist and are readable
 *
 * @param paths Array of texture paths to check
 * @return true If all paths are valid
 * @return false If any path is invalid or missing
 */
static bool	validate_texture_paths(char **paths)
{
	int	i;

	if (!paths)
		return (false);
	i = 0;
	while (i < 4)
	{
		if (!paths[i])
		{
			ft_printf(RED "Error\nTexture file not found: %s\n" RESET,
				paths[i] ? paths[i] : "NULL");
			return (false);
		}
		i++;
	}
	return (true);
}

/**
 * @brief Free array of resolved texture paths
 *
 * @param paths Array of paths to free
 */
static void	free_resolved_paths(char **paths)
{
	int	i;

	if (!paths)
		return ;
	i = 0;
	while (i < 4)
	{
		if (paths[i])
			free(paths[i]);
		i++;
	}
	free(paths);
}

/**
 * @brief Load all game textures from parsed paths
 *
 * @param data App data containing texture paths
 * @return true On error
 * @return false On success
 */
bool	load_game_textures(t_data *data)
{
	char	**resolved_paths;
	bool	success;

	if (!data || !data->texture_n || !data->texture_e || !data->texture_s
		|| !data->texture_w)
	{
		ft_printf(RED "Error\nMissing texture paths\n" RESET);
		return (true);
	}
	resolved_paths = resolve_texture_paths(data, data->map_file_path);
	if (!resolved_paths)
	{
		ft_printf(RED "Error\nFailed to resolve texture paths\n" RESET);
		return (true);
	}
	if (!validate_texture_paths(resolved_paths))
	{
		free_resolved_paths(resolved_paths);
		return (true);
	}
	success = load_textures(&data->textures, data->mlx, resolved_paths);
	free_resolved_paths(resolved_paths);
	if (!success)
	{
		ft_printf(RED "Error\nFailed to load textures\n" RESET);
		return (true);
	}
	return (false);
}
