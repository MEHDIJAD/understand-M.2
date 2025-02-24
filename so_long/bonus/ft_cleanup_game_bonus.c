/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup_game_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:18:24 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/21 20:44:19 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_cleanup_game(t_data *data)
{
	if (data->img_hero)
		mlx_destroy_image(data->mlx, data->img_hero);
	if (data->img_wall)
		mlx_destroy_image(data->mlx, data->img_wall);
	if (data->img_floor)
		mlx_destroy_image(data->mlx, data->img_floor);
	if (data->img_collact)
		mlx_destroy_image(data->mlx, data->img_collact);
	if (data->img_exit)
		mlx_destroy_image(data->mlx, data->img_exit);
	if (data->img_enemy)
		mlx_destroy_image(data->mlx, data->img_enemy);
	if (data->img_exit_open)
		mlx_destroy_image(data->mlx, data->img_exit_open);
	if (data->enemies)
		free(data->enemies);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->ptr)
		ft_free_map(data->ptr);
}
