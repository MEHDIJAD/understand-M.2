/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_collectibles.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:26:05 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/22 11:22:57 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_count_collectibles(t_data *data)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < data->x)
	{
		j = 0;
		while (j < data->y)
		{
			if (data->ptr[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
