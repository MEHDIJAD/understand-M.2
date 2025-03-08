/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_move_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:19:00 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 14:41:05 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static void	ft_display_moves(t_data *data, int movement_count)
{
	char	*movement_countstr;

	mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, "Movements: ");
	movement_countstr = ft_itoa(movement_count);
	mlx_string_put(data->mlx, data->win, 100, 10, 0xFFFFFF, movement_countstr);
	free(movement_countstr);
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
			return (ft_printf(1, "CONGRATS! YOU WIN!\n"), ft_exit(data), 0);
	}
	if (next_pos == 'T')
		return (ft_printf(1, "GAME OVER!, YOU LOST\n"), ft_exit(data), 0);
	if (next_pos != '1')
	{
		pos = ft_helper_function(data->x_p, data->y_p, new_x, new_y);
		ft_update_map(data, pos);
		ft_update_pos(data, new_x, new_y);
		(*movement_count)++;
		ft_drow_map(data);
		ft_display_moves(data, *movement_count);
	}
	return (0);
}
