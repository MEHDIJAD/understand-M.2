/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving_player_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:15:03 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 14:41:31 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_first_move(int keycode, t_data *data)
{
	static int	movement_count;

	ft_get_player_position(data);
	if (keycode == 65307)
		ft_exit(data);
	if (keycode == 100)
		put_move(data, data->y_p, data->x_p + 1, &movement_count);
	if (keycode == 97)
		put_move(data, data->y_p, data->x_p - 1, &movement_count);
	if (keycode == 115)
		put_move(data, data->y_p + 1, data->x_p, &movement_count);
	if (keycode == 119)
		put_move(data, data->y_p - 1, data->x_p, &movement_count);
	if (!ft_count_collectibles(data))
		ft_put_open_door(data);
	if (!ft_count_collectibles(data) && data->ptr[data->y_p][data->x_p] == 'E')
	{
		ft_printf(1, "CONGRATULATIONS! YOU WIN!\n");
		ft_exit(data);
	}
	return (0);
}
