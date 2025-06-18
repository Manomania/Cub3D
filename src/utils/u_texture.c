/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_texture.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:39:02 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/17 19:24:47 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file contains mainly stuff for resolving paths.
*/

#include "cub3d.h"
#include "texture.h"
#include "utils.h"

/*
** Resolve all texture paths relative to the map file
*/
static char	**resolve_texture_paths(t_data *data, const char *map_path)
{
	char	**resolved_paths;

	resolved_paths = ft_calloc(6, sizeof(char *));
	if (!resolved_paths)
		return (NULL);
	resolved_paths[0] = resolve_path(map_path, data->texture_n);
	resolved_paths[1] = resolve_path(map_path, data->texture_e);
	resolved_paths[2] = resolve_path(map_path, data->texture_s);
	resolved_paths[3] = resolve_path(map_path, data->texture_w);
	if (BUILD_BONUS)
		resolved_paths[4] = resolve_path(map_path, data->texture_door);
	return (resolved_paths);
}

/*
** Free array of resolved texture paths
*/
static bool	free_resolved_paths(char **paths)
{
	int	i;

	if (!paths)
		return (true);
	i = 0;
	while (i < 4)
	{
		if (paths[i])
			free(paths[i]);
		i++;
	}
	free(paths);
	return (true);
}

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
	success = load_textures(&data->textures, data->mlx, resolved_paths);
	free_resolved_paths(resolved_paths);
	if (!success)
	{
		ft_printf(RED "Error\nFailed to load textures\n" RESET);
		return (true);
	}
	if (load_game_textures_bonus(data))
		return (true);
	return (false);
}
