/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:44:35 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/17 15:25:21 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(void)
{
	perror("Error");
	exit (1);
}

char	**get_map(char *av)
{
	char	*line;
	char	*all_lines;
	int		mapfd;
	char	**res;

	line = "";
	all_lines = "";
	mapfd = open(av, O_RDONLY);
	while (1)
	{
		line = get_next_line(mapfd);
		if (line == NULL)
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	close(mapfd);
	if (all_lines[0] == '\0')
	{
		error_message();
	}
	free(line);
	res = ft_split(all_lines, '\n');
	free(all_lines);
	return (res);
}
