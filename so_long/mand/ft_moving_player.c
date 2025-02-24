/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:34:48 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/21 19:14:38 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_first_move(int keycode, t_data *data)
{
	static int	movement_count;

	ft_get_player_position(data);
	if (keycode == XK_Escape)
		ft_exit(data);
	if (keycode == 100)
		put_move(data, data->y_p, data->x_p + 1, &movement_count);
	if (keycode == 97)
		put_move(data, data->y_p, data->x_p - 1, &movement_count);
	if (keycode == 115)
		put_move(data, data->y_p + 1, data->x_p, &movement_count);
	if (keycode == 119)
		put_move(data, data->y_p - 1, data->x_p, &movement_count);
	return (0);
}
