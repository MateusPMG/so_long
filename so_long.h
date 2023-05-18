/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:43:19 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/18 16:35:52 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
//lib for 'open' function
# include <fcntl.h>
//lib for 'acess' and 'write'
# include <unistd.h>
//lib for mlx
# include "./mlx_linux/mlx.h"
//lib for keyhandles
# include <X11/keysym.h>

typedef struct map
{
	int	p;
	int	c;
	int	e;
	int	x;
	int	y;
}	t_map;

typedef struct vars
{
	int	x_start;
	int	y_start;
	int	x;
	int	y;
}	t_vars;

typedef struct data
{
	char		**map;
	t_vars		size;
	t_vars		position;
	void		*mlx_ptr;
	void		*win_ptr;
}	t_data;

int		validate_file(char *av);
int		get_height(char **map);
void	error_message(void);
void	error_free(t_data **data);
void	check_path_values(t_data **data);
char	**get_map(char *av);
void	validate_map(t_data *data);
void	check_c(t_data **d);
void	check_e(t_data **d);
void	check_o(t_data **d);
void	check_rectangular(t_data **data);
void	free_mlx(t_data *data);

#endif
