/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_img_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:19:19 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/21 17:07:24 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_get_img_data(t_data *data)
{
	data->img_hero = mlx_xpm_file_to_image(data->mlx,
			data->relative_path_hero, &data->img_widht, &data->img_height);
	if (!data->img_hero)
		return (ft_printf(2, "Failed: hero image"), ft_exit(data), 0);
	data->img_wall = mlx_xpm_file_to_image(data->mlx,
			data->relative_path_wall, &data->img_widht, &data->img_height);
	if (!data->img_wall)
		return (ft_printf(2, "Failed: wall image"), ft_exit(data), 0);
	data->img_floor = mlx_xpm_file_to_image(data->mlx,
			data->relative_path_floor, &data->img_widht, &data->img_height);
	if (!data->img_floor)
		return (ft_printf(2, "Failed: floor image"), ft_exit(data), 0);
	data->img_collact = mlx_xpm_file_to_image(data->mlx,
			data->relative_path_collact, &data->img_widht, &data->img_height);
	if (!data->img_collact)
		return (ft_printf(2, "Failed: collectible image"), ft_exit(data), 0);
	data->img_exit = mlx_xpm_file_to_image(data->mlx,
			data->relative_path_exit, &data->img_widht, &data->img_height);
	if (!data->img_exit)
		return (ft_printf(2, "Failed: exit image"), ft_exit(data), 0);
	return (1);
}
