/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:33:13 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 14:41:29 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_enemy_count(t_data *data)
{
	size_t	enemy_count;
	int		i;
	int		j;

	enemy_count = 0;
	i = 0;
	while (i < data->x && data->ptr[i])
	{
		j = 0;
		while (j < data->y && data->ptr[i][j])
		{
			if (data->ptr[i][j] == 'T')
				enemy_count++;
			j++;
		}
		i++;
	}
	return (enemy_count);
}

int	ft_get_enemy_positions(t_data *data)
{
	int	i;
	int	j;
	int	p;

	data->enemy_count = ft_enemy_count(data);
	data->enemies = malloc(sizeof(t_enemy) * data->enemy_count);
	if (!data->enemies)
		return (ft_printf(2, "Error\nMALLOC FAILED!"), ft_exit(data), 1);
	p = 0;
	i = -1;
	while (++i < data->x)
	{
		j = -1;
		while (++j < data->y)
		{
			if (data->ptr[i][j] == 'T')
			{
				data->enemies[p].x = i;
				data->enemies[p].y = j;
				data->enemies[p].direction = 1;
				p++;
			}
		}
	}
	return (1);
}

void	ft_move_enemy(t_data *data, t_enemy *enemy)
{
	int	new_enemy_y;

	new_enemy_y = enemy->y + enemy->direction;
	if (data->ptr[enemy->x][new_enemy_y] != '1' &&
		data->ptr[enemy->x][new_enemy_y] != 'C' &&
		data->ptr[enemy->x][new_enemy_y] != 'E')
	{
		if (data->ptr[enemy->x][new_enemy_y] == 'P')
		{
			ft_printf(1, "GAME OVER!, YOU LOST\n");
			ft_exit(data);
		}
		ft_put_image(data, enemy->x, new_enemy_y, 'T');
		ft_put_image(data, enemy->x, enemy->y, '0');
		data->ptr[enemy->x][enemy->y] = '0';
		data->ptr[enemy->x][new_enemy_y] = 'T';
		enemy->y = new_enemy_y;
	}
	else
	{
		enemy->direction *= -1;
	}		
}

int	ft_moving_enemy(t_data *data)
{
	size_t		i;
	static int	frame;

	frame++;
	if (frame % 20000 != 0)
		return (0);
	if (!data->enemies)
		return (0);
	i = 0;
	while (i < data->enemy_count)
	{
		ft_move_enemy(data, &data->enemies[i]);
		i++;
	}
	return (0);
}
