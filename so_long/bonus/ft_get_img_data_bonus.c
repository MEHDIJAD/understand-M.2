/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_img_data_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:19:19 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/22 11:25:36 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_helper(t_data *data)
{
	data->img_enemy = mlx_xpm_file_to_image(data->mlx,
			data->relative_path_enemy, &data->img_widht, &data->img_height);
	if (!data->img_enemy)
		return (ft_printf(2, "Failed enemy image"), ft_exit(data), 0);
	data->img_exit_open = mlx_xpm_file_to_image(data->mlx,
			data->relative_path_exit_open, &data->img_widht, &data->img_height);
	if (!data->img_exit_open)
		return (ft_printf(2, "Failed exit_open image"), ft_exit(data), 0);
	return (1);
}

int	ft_get_img_data(t_data *data)
{
	data->img_hero = mlx_xpm_file_to_image(data->mlx, data->relative_path_hero,
			&data->img_widht, &data->img_height);
	if (!data->img_hero)
		return (ft_printf(2, "Failed hero image"), ft_exit(data), 0);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, data->relative_path_wall,
			&data->img_widht, &data->img_height);
	if (!data->img_wall)
		return (ft_printf(2, "Failed wall image"), ft_exit(data), 0);
	data->img_floor = mlx_xpm_file_to_image(data->mlx,
			data->relative_path_floor, &data->img_widht, &data->img_height);
	if (!data->img_floor)
		return (ft_printf(2, "Failed floor image"), ft_exit(data), 0);
	data->img_collact = mlx_xpm_file_to_image(data->mlx,
			data->relative_path_collact, &data->img_widht, &data->img_height);
	if (!data->img_collact)
		return (ft_printf(2, "Failed: collectible image"), ft_exit(data), 0);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, data->relative_path_exit,
			&data->img_widht, &data->img_height);
	if (!data->img_exit)
		return (ft_printf(2, "Failed exit image"), ft_exit(data), 0);
	if (!ft_helper(data))
		return (0);
	return (1);
}
