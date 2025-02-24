/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:19:00 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/21 17:07:00 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_position	ft_helper_function(int old_x, int old_y,
	int new_x, int new_y)
{
	t_position	pos;

	pos.old_x = old_x;
	pos.old_y = old_y;
	pos.new_x = new_x;
	pos.new_y = new_y;
	return (pos);
}

static void	ft_update_map(t_data *data, t_position pos)
{
	ft_put_image(data, pos.old_y, pos.old_x, '0');
	ft_put_image(data, pos.new_y, pos.new_x, 'P');
}

static void	ft_update_pos(t_data *data, int new_x, int new_y)
{
	data->ptr[data->y_p][data->x_p] = '0';
	data->ptr[new_y][new_x] = 'P';
	data->y_p = new_y;
	data->x_p = new_x;
}

int	put_move(t_data *data, int new_y, int new_x, int *movement_count)
{
	char		next_pos;
	t_position	pos;

	next_pos = data->ptr[new_y][new_x];
	if (next_pos == 'C')
		data->cl--;
	else if (next_pos == 'E')
	{
		if (data->cl != 0)
			return (0);
		if (data->cl == 0)
		{
			ft_printf(2, "Movements: %d\n", ++(*movement_count));
			ft_printf(1, "GAME OVER!, YOU WIN!\n");
			ft_exit(data);
		}
	}
	if (next_pos != '1')
	{
		pos = ft_helper_function(data->x_p, data->y_p, new_x, new_y);
		ft_update_map(data, pos);
		ft_update_pos(data, new_x, new_y);
		ft_printf(2, "Movements: %d\n", ++(*movement_count));
	}
	return (0);
}
