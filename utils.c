/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:07:28 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/25 14:31:19 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_e(t_data *d)
{
	int	e;
	int	x;
	int	y;

	e = 0;
	y = 0;
	while ((d)->map[y] != NULL)
	{
		x = 0;
		while ((d)->map[y][x] != '\0')
		{
			if ((d)->map[y][x] == 'e')
			{
				e++;
				(d)->map[y][x] = 'E';
			}
			x++;
		}
		y++;
	}
	if (e == 0)
	{
		write(1, "No path to exit\n", 16);
		exit(1);
	}
}

void	check_o(t_data *d)
{
	int	o;
	int	x;
	int	y;

	o = 0;
	y = 0;
	while ((d)->map[y] != NULL)
	{
		x = 0;
		while ((d)->map[y][x] != '\0')
		{
			if ((d)->map[y][x] == 'o')
			{
				o++;
				(d)->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}
