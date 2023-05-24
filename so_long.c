/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:43:04 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/24 16:14:37 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data **data)
{
	mlx_destroy_window((*data)->mlx_ptr, (*data)->win_ptr);
	return (0);
}

void	init_size(t_data *data)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	data->sprite = sprite;
	data->size.x = 0;
	data->size.y = 0;
	while (data->map[data->size.y])
		data->size.y++;
	while (data->map[0][data->size.x] != '\n')
		data->size.x++;
}

void	mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit(1);
	init_size(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, (data->size.x) * 50,
			(data->size.y) * 50, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		exit(1);
	}
	c_count(data);
	get_image(data);
	add_image(data);
	mlx_hook(data->win_ptr, 17, 1L << 17, close_window, &data);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_handler, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	data = (t_data *)malloc(sizeof(t_data));
	if (ac != 2)
	{
		perror("Error");
		exit(1);
	}
	if (!validate_file(av[1]))
		return (0);
	data->map = get_map(av[1]);
	if (data->map != NULL)
	{
		validate_map(data);
		mlx(data);
	}
	free_mlx(data);
	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	return (0);
}
