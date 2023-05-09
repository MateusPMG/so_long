/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:04:49 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/09 15:11:29 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	check_rectangular(t_data **data)
{
	
}

void	validate_map(t_data *data)
{
	check_rectangular(&data);
	check_walls();
	check_elements();
}
