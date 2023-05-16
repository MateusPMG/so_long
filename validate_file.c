/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:55:29 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/16 15:06:03 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_file(char *av)
{
	int	len;

	if (access(av, 0) != 0)
	{
		perror("Error");
		return (0);
	}
	len = ft_strlen(av);
	if (ft_strncmp(&av[len - 4], ".ber", 4) != 0)
	{
		write(1, "incorrect map file type", 23);
		return (0);
	}
	return (1);
}
