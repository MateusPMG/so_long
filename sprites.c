/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:23:58 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/30 12:05:58 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_image(t_data *data)
{
	int	h;

	h = 50;
	data->sprite->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall.xpm", &h, &h);
	data->sprite->player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/player.xpm", &h, &h);
	data->sprite->exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit.xpm", &h, &h);
	data->sprite->collectible = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/collectible.xpm", &h, &h);
	data->sprite->path = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/path.xpm", &h, &h);
	data->sprite->overlap = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/overlap.xpm", &h, &h);
}

void	image_selection(t_data *data, int height, int width)
{
	if (data->map[height][width] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite->wall, width * 50, height * 50);
	else if (data->map[height][width] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite->collectible, width * 50, height * 50);
	else if (data->map[height][width] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite->player, width * 50, height * 50);
	else if (data->map[height][width] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite->exit, width * 50, height * 50);
	else if (data->map[height][width] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite->path, width * 50, height * 50);
	else if (data->map[height][width] == 'K')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite->overlap, width * 50, height * 50);
}

void	add_image(t_data *data)
{
	int	height;
	int	width;

	height = 0;
	while (height < data->size.y)
	{
		width = 0;
		while (width < data->size.x)
		{
			image_selection(data, height, width);
			width++;
		}
		height++;
	}
}
