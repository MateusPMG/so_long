/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:29:29 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/25 14:29:53 by mpatrao          ###   ########.fr       */
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

void	error_free(t_data *data)
{
	int	i;

	i = 0;
	while ((data)->map[i] != NULL)
	{
		free((data)->map[i]);
		i++;
	}
	free((data)->map);
	write(1, "Error\nWrong Format\n", 19);
	exit(1);
}

void	check_path(char **map, t_vars size)
{
	if ((map[size.y_start][size.x_start] != '0'
		&& map[size.y_start][size.x_start] != 'C'
		&& map[size.y_start][size.x_start] != 'P'
		&& map[size.y_start][size.x_start] != 'E')
		|| size.x_start < 0 || size.y_start < 0 ||
		size.x_start >= size.x || size.y_start >= size.y)
		return ;
	if (map[size.y_start][size.x_start] == 'E')
		map[size.y_start][size.x_start] = 'e';
	if (map[size.y_start][size.x_start] == 'P')
		map[size.y_start][size.x_start] = 'p';
	if (map[size.y_start][size.x_start] == 'C')
		map[size.y_start][size.x_start] = 'c';
	if (map[size.y_start][size.x_start] == '0')
		map[size.y_start][size.x_start] = 'o';
	check_path(map, (t_vars){size.x_start + 1, size.y_start, size.x, size.y});
	check_path(map, (t_vars){size.x_start - 1, size.y_start, size.x, size.y});
	check_path(map, (t_vars){size.x_start, size.y_start + 1, size.x, size.y});
	check_path(map, (t_vars){size.x_start, size.y_start - 1, size.x, size.y});
}

void	check_path_values(t_data *data)
{
	t_vars		size;
	int			x;
	int			y;

	size.y = get_height((data)->map) - 1;
	size.x = 0;
	while ((data)->map[size.y][size.x] != '\0')
		size.x++;
	size.x--;
	y = size.y;
	while (y--)
	{
		x = 0;
		while ((data)->map[y][x] != '\0')
		{
			if ((data)->map[y][x] == 'P')
			{
				size.x_start = x;
				size.y_start = y;
			}
			x++;
		}
	}
	check_path((data)->map, size);
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
		write(1, "No path to collectible", 22);
		exit(1);
	}
}
