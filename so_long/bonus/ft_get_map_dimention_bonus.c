/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_dimention_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:19:52 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 14:41:18 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_get_map_dimention(t_data *data)
{
	int	x;
	int	y;
	int	c;

	x = 0;
	c = 0;
	while (data->ptr[x])
	{
		y = 0;
		while (data->ptr[x][y])
		{
			if (data->ptr[x][y] == 'C')
				c++;
			y++;
		}
		x++;
	}
	data->x = x;
	data->y = y;
	data->cl = c;
	return (1);
}
