/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:43:04 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/17 15:06:12 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if (ac != 2)
	{
		perror("Error");
		exit(1);
	}
	if (!validate_file(av[1]))
		return (0);
	data.map = get_map(av[1]);
	if (data.map != NULL)
	{
		validate_map(&data);
	}
	i = 0;
	while (data.map[i])
	{
		free(data.map[i]);
		i++;
	}
	free(data.map);
}
