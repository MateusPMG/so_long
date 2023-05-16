/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:44:35 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/16 15:07:56 by mpatrao          ###   ########.fr       */
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

	line = "";
	all_lines = ft_strdup("");
	mapfd = open(av, O_RDONLY);
	if (mapfd == -1)
		error_message();
	while (1)
	{
		line = get_next_line(mapfd);
		if (line == NULL || line[0] == '\n')
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	free(line);
	close(mapfd);
	if (all_lines[0] == '\0')
		error_message();
	return (ft_split(all_lines, '\n'));
}
