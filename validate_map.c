/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:04:49 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/09 15:43:16 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	check_rectangular(t_data **data)
{
	int	map_x;
	int	map_y;
	int	height;
	int	flag;

	map_y = 0;
	flag = 0;
	height = get_height((*data)->map);
	while (map_y != height)
	{
		map_x = 0;
		while ((*data)->map[map_y][map_x] != '\0')
			map_x++;
		map_y++;
		if (flag != 0)
		{
			if (flag != map_x)
				error_message();
		}
		else
			flag = map_x;
	}
}

void	check_walls(t_data **data)
{
	
}

void	validate_map(t_data *data)
{
	check_rectangular(&data);
	check_walls();
	check_elements();
}
