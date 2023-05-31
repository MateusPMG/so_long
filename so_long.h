/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:43:19 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/30 13:31:33 by mpatrao          ###   ########.fr       */
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

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct sprite
{
	void		*wall;
	void		*collectible;
	void		*player;
	void		*path;
	void		*exit;
	void		*overlap;
}				t_sprite;

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
	void		*mlx_ptr;
	void		*win_ptr;
	t_sprite	*sprite;
	int			c;
	int			moves;
}	t_data;

int		validate_file(char *av);
int		get_height(char **map);
void	error_message(void);
void	error_free(t_data *data, int j);
void	check_path_values(t_data *data);
char	**get_map(char *av);
void	validate_map(t_data *data);
void	check_c(t_data *d);
void	check_e(t_data *d);
void	check_o(t_data *d);
void	check_rectangular(t_data *data);
void	free_mlx(t_data *data);
void	get_image(t_data *data);
int		key_handler(int keycode, t_data *data);
void	add_image(t_data *data);
void	check_p(t_data *d);
void	c_count(t_data *d);
int		end_game(t_data *data, int y, int x);
void	image_selection(t_data *data, int height, int width);
int		close_handler(t_data *data);
void	k_or_p(t_data *data, t_vars cords);

#endif
