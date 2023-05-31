/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:29:29 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/30 13:48:08 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

void	error_free(t_data *data, int j)
{
	int	i;

	i = 0;
	while ((data)->map[i] != NULL)
	{
		free((data)->map[i]);
		i++;
	}
	free((data)->map);
	if (j == 0)
		write(1, "Error\nNot Rectangular\n", 22);
	else if (j == 1)
		write(1, "Error\nNot Enclosed\n", 19);
	else if (j == 2)
		write(1, "Error\nWrong element\n", 20);
	else if (j == 3)
		write(1, "Error\nWrong amount of a given element\n", 38);
	exit(1);
}

void	check_path(t_data *data, t_vars	s)
{
	if ((data->map[s.y_start][s.x_start] != '0'
		&& data->map[s.y_start][s.x_start] != 'C'
		&& data->map[s.y_start][s.x_start] != 'P'
		&& data->map[s.y_start][s.x_start] != 'E')
		|| s.x_start < 0 || s.y_start < 0 ||
		s.x_start >= s.x
			|| s.y_start >= s.y)
		return ;
	if (data->map[s.y_start][s.x_start] == 'E')
		data->map[s.y_start][s.x_start] = 'e';
	if (data->map[s.y_start][s.x_start] == 'P')
		data->map[s.y_start][s.x_start] = 'p';
	if (data->map[s.y_start][s.x_start] == 'C')
		data->map[s.y_start][s.x_start] = 'c';
	if (data->map[s.y_start][s.x_start] == '0')
		data->map[s.y_start][s.x_start] = 'o';
	check_path(data, (t_vars){s.x_start + 1, s.y_start,
		s.x, s.y});
	check_path(data, (t_vars){s.x_start - 1, s.y_start,
		s.x, s.y});
	check_path(data, (t_vars){s.x_start, s.y_start + 1,
		s.x, s.y});
	check_path(data, (t_vars){s.x_start, s.y_start - 1,
		s.x, s.y});
}

void	check_path_values(t_data *data)
{
	int			x;
	int			y;

	data->size.y = get_height((data)->map) - 1;
	data->size.x = 0;
	while ((data)->map[data->size.y][data->size.x] != '\0')
		data->size.x++;
	data->size.x--;
	y = data->size.y;
	while (y--)
	{
		x = 0;
		while ((data)->map[y][x] != '\0')
		{
			if ((data)->map[y][x] == 'P')
			{
				data->size.x_start = x;
				data->size.y_start = y;
			}
			x++;
		}
	}
	check_path(data, data->size);
}

void	check_c(t_data *d)
{
	int	c;
	int	x;
	int	y;

	c = 0;
	y = 0;
	while ((d)->map[y] != NULL)
	{
		x = 0;
		while ((d)->map[y][x] != '\0')
		{
			if ((d)->map[y][x] == 'c')
			{
				c++;
				(d)->map[y][x] = 'C';
			}
			x++;
		}
		y++;
	}
	if (c == 0)
	{
		write(1, "Error\nNo path to collectible\n", 29);
		exit(1);
	}
}
