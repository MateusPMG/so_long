/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:06 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/25 14:54:21 by mpatrao          ###   ########.fr       */
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
		if (!(end_game(data, y - 1, x)))
			return ;
		data->size.y_start--;
		data->map[y - 1][x] = 'P';
		data->map[y][x] = '0';
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
		if (!(end_game(data, y + 1, x)))
			return ;
		data->size.y_start++;
		data->map[y + 1][x] = 'P';
		data->map[y][x] = '0';
		image_selection(data, y, x);
		image_selection(data, y + 1, x);
		data->moves++;
		ft_printf("Total of moves:%d\n", data->moves);
	}
}

int	key_handler(t_data *data, int keycode)
{
	if (keycode == 65307)
	{
		write(1, "ok\n", 3);
		close_window(data);
		exit(1);
	}
	if (keycode == 1)
		move_up(data);
	if (keycode == 13)
		move_down(data);
	//if (keycode == XK_Left || keycode == XK_a)
		//move_left(data);
	//if (keycode == XK_Right || keycode == XK_d)
		//move_right(data);
	return (1);
}
