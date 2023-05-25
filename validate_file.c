/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:55:29 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/25 14:30:43 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_file(char *av)
{
	int	len;

	if (access(av, 0) != 0)
	{
		perror("Error");
		return (0);
	}
	len = ft_strlen(av);
	if (ft_strncmp(&av[len - 4], ".ber", 4) != 0)
	{
		write(1, "incorrect map file type", 23);
		return (0);
	}
	return (1);
}

int	end_game(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'C')
		data->c--;
	else if (data->map[y][x] == 'E' && data->c > 0)
		return (0);
	else if (data->map[y][x] == 'E' && data->c == 0)
	{
		data->moves++;
		ft_printf("You won!! Game ended in %d moves\n", data->moves);
		exit(1);
	}
	return (1);
}

void	c_count(t_data *d)
{
	int	x;
	int	y;

	d->moves = 0;
	d->c = 0;
	y = 0;
	while (d->map[y] != NULL)
	{
		x = 0;
		while (d->map[y][x] != '\0')
		{
			if (d->map[y][x] == 'C')
			{
				d->c++;
			}
			x++;
		}
		y++;
	}
}

void	check_p(t_data *d)
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
			if ((d)->map[y][x] == 'p')
			{
				c++;
				(d)->map[y][x] = 'P';
			}
			x++;
		}
		y++;
	}
	if (c == 0)
	{
		write(1, "No path to player", 22);
		exit(1);
	}
}
