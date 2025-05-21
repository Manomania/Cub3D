/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:57:10 by elagouch          #+#    #+#             */
/*   Updated: 2025/05/19 16:10:31 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include "mlx.h"

void	free_map(t_data *data)
{
	int	i;

	if (!data->map)
		return ;
	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
}

static void	free_textures(t_data *data)
{
	if (data->textures.north.img)
		mlx_destroy_image(data->mlx, data->textures.north.img);
	if (data->textures.south.img)
		mlx_destroy_image(data->mlx, data->textures.south.img);
	if (data->textures.east.img)
		mlx_destroy_image(data->mlx, data->textures.east.img);
	if (data->textures.west.img)
		mlx_destroy_image(data->mlx, data->textures.west.img);
}

static void	free_paths(t_data *data)
{
	if (data->texture_n)
		free(data->texture_n);
	if (data->texture_s)
		free(data->texture_s);
	if (data->texture_e)
		free(data->texture_e);
	if (data->texture_w)
		free(data->texture_w);
}

void	*free_ressource(t_data *data)
{
	if (!data)
		return (NULL);
	if (data->map)
	{
		free_map(data);
		data->map = NULL;
	}
	free_paths(data);
	free_textures(data);
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	return (NULL);
}
