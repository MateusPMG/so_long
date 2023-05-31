/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:06 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/30 13:17:07 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	int	y;
	int	x;

	y = data->size.y_start;
	x = data->size.x_start;
	if ((y - 1 > 0) && (data->map[y - 1][x] != '1'))
	{
		end_game(data, y - 1, x);
		if (data->map[y - 1][x] == 'E' && data->c)
		{
			data->map[y - 1][x] = 'K';
			data->map[y][x] = '0';
		}
		else
			k_or_p(data, (t_vars){data->size.x_start,
				data->size.y_start, 0, -1});
		data->size.y_start--;
		image_selection(data, y, x);
		image_selection(data, y - 1, x);
		data->moves++;
		ft_printf("Total of moves:%d\n", data->moves);
	}
}

void	move_down(t_data *data)
{
	int	y;
	int	x;

	y = data->size.y_start;
	x = data->size.x_start;
	if ((y + 1 < data->size.y) && (data->map[y + 1][x] != '1'))
	{
		end_game(data, y + 1, x);
		if (data->map[y + 1][x] == 'E' && data->c)
		{
			data->map[y + 1][x] = 'K';
			data->map[y][x] = '0';
		}
		else
			k_or_p(data, (t_vars){data->size.x_start,
				data->size.y_start, 0, 1});
		data->size.y_start++;
		image_selection(data, y, x);
		image_selection(data, y + 1, x);
		data->moves++;
		ft_printf("Total of moves:%d\n", data->moves);
	}
}

void	move_left(t_data *data)
{
	int	y;
	int	x;

	y = data->size.y_start;
	x = data->size.x_start;
	if ((x - 1 > 0) && (data->map[y][x - 1] != '1'))
	{
		end_game(data, y, x - 1);
		if (data->map[y][x - 1] == 'E' && data->c)
		{
			data->map[y][x - 1] = 'K';
			data->map[y][x] = '0';
		}
		else
			k_or_p(data, (t_vars){data->size.x_start,
				data->size.y_start, -1, 0});
		data->size.x_start--;
		image_selection(data, y, x);
		image_selection(data, y, x - 1);
		data->moves++;
		ft_printf("Total of moves:%d\n", data->moves);
	}
}

void	move_right(t_data *data)
{
	int	y;
	int	x;

	y = data->size.y_start;
	x = data->size.x_start;
	if ((x + 1 < data->size.x) && (data->map[y][x + 1] != '1'))
	{
		end_game(data, y, x + 1);
		if (data->map[y][x + 1] == 'E' && data->c)
		{
			data->map[y][x + 1] = 'K';
			data->map[y][x] = '0';
		}
		else
			k_or_p(data, (t_vars){data->size.x_start,
				data->size.y_start, 1, 0});
		data->size.x_start++;
		image_selection(data, y, x);
		image_selection(data, y, x + 1);
		data->moves++;
		ft_printf("Total of moves:%d\n", data->moves);
	}
}

int	key_handler(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		close_handler(data);
		exit(0);
	}
	else if (keycode == 119)
		move_up(data);
	else if (keycode == 115)
		move_down(data);
	if (keycode == XK_Left || keycode == XK_a)
		move_left(data);
	if (keycode == XK_Right || keycode == XK_d)
		move_right(data);
	return (1);
}
