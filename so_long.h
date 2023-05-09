/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:43:19 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/09 14:38:22 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
//lib for 'open' function
# include <fcntl.h>

typedef struct measures
{
	int	x;
	int	y;
}	t_measures;

typedef struct data
{
	char		**map;
	t_measures	size;
	t_measures	position;
}	t_data;

int		validate_file(char *av);

#endif
