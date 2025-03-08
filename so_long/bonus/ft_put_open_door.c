/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_open_door.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:50:42 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 14:41:39 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_exit_position(t_data *data, t_exit *exit)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->x && data->ptr[i])
	{
		j = 0;
		while (j < data->y && data->ptr[i][j])
		{
			if (data->ptr[i][j] == 'E')
			{
				exit->x = i;
				exit->y = j;
			}
			j++;
		}
		i++;
	}
}

int	ft_put_open_door(t_data *data)
{
	t_exit	exit;

	ft_exit_position(data, &exit);
	mlx_put_image_to_window(data->mlx, data->win, data->img_exit_open,
		(exit.y * data->img_widht), (exit.x * data->img_height));
	mlx_do_sync(data->mlx);
	return (0);
}
