/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:44:35 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/18 12:13:48 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_res(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	write(1, "Error:\nEmpty Map\n", 17);
	exit(1);
}

void	error_message(void)
{
	perror("Error");
	exit (1);
}

int	ft_count_lines(char *av)
{
	char	*line;
	int		fd1;
	int		i;

	fd1 = open(av, O_RDONLY);
	i = 0;
	line = get_next_line(fd1);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd1);
	}
	free(line);
	close(fd1);
	return (i);
}

char	**get_map(char *av)
{
	int		mapfd;
	char	**res;
	int		count;
	int		i;

	count = ft_count_lines(av);
	res = (char **)malloc((count + 1) * sizeof(char *));
	i = 0;
	mapfd = open(av, O_RDONLY);
	if (mapfd < 0)
		return (0);
	while (i < count)
	{
		res[i] = get_next_line(mapfd);
		i++;
	}
	res[i] = NULL;
	if (res[0] == NULL)
		free_res(res);
	close(mapfd);
	return (res);
}
