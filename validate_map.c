/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:04:49 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/17 14:41:04 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangular(t_data **data)
{
	size_t	flag;
	int		i;

	i = 0;
	flag = ft_strlen((*data)->map[0]);
	while ((*data)->map[i])
	{
		if (ft_strlen((*data)->map[i]) != flag)
			error_free(data);
		i++;
	}
}

void	check_walls(t_data **data)
{
	int	y;
	int	x;

	y = 0;
	while ((*data)->map[y] != NULL)
	{
		if ((*data)->map[y][0] != '1')
			error_free(data);
		y++;
	}
	x = 0;
	while ((*data)->map[0][x] != '\0' && (*data)->map[y - 1][x] != '\0')
	{
		if ((*data)->map[0][x] != '1' || (*data)->map[y - 1][x] != '1')
			error_free(data);
		x++;
	}
	while ((*data)->map[y - 2] != (*data)->map[0])
	{
		if ((*data)->map[y - 2][x - 1] != '1')
			error_free(data);
		y--;
	}
}

void	check_elements(t_data **data)
{
	t_map	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.y = get_height((*data)->map) - 1;
	while (map.y--)
	{
		map.x = 0;
		while ((*data)->map[map.y][map.x] != '\0')
		{
			if ((*data)->map[map.y][map.x] == 'P')
				map.p++;
			else if ((*data)->map[map.y][map.x] == 'C')
				map.c++;
			else if ((*data)->map[map.y][map.x] == 'E')
				map.e++;
			else if ((*data)->map[map.y][map.x] != '1'
				&& (*data)->map[map.y][map.x] != '0')
				error_free(data);
			map.x++;
		}
	}
	if (map.c == 0 || map.e != 1 || map.p != 1)
		error_free(data);
}

void	check_path_elements(t_data **d)
{
	check_c(d);
	check_e(d);
	check_o(d);
}

void	validate_map(t_data *data)
{
	check_rectangular(&data);
	check_walls(&data);
	check_elements(&data);
	check_path_values(&data);
	check_path_elements(&data);
}
