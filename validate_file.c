/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:55:29 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/09 13:43:47 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_file(char *av)
{
	int	len;

	if (acess(av[1], 0) != 0)
	{
		perror("Error");
		return (0);
	}
	len = ft_strlen(av[1]);
	if (ft_strncmp(av[len - 4], ".ber", 4))
	{
		write(1, "incorrect map file type", 23);
		return (0);
	}
	return (1);
}
