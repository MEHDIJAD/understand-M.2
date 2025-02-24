/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:20:30 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/22 12:01:48 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_helper_function_int(t_data *data)
{
	data->x_p = 0;
	data->y_p = 0;
	data->cl = 0;
	data->img_widht = 0;
	data->img_height = 0;
}

void	ft_init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img_hero = NULL;
	data->img_wall = NULL;
	data->img_floor = NULL;
	data->img_collact = NULL;
	data->img_exit = NULL;
	data->img_enemy = NULL;
	data->img_exit_open = NULL;
	data->ptr = NULL ;
	data->relative_path_hero = "/home/eel-garo/Desktop/M.2/so_long/"
		"textures/player.xpm";
	data->relative_path_wall = "/home/eel-garo/Desktop/M.2/so_long/"
		"textures/block.xpm";
	data->relative_path_collact = "/home/eel-garo/Desktop/M.2/so_long/"
		"textures/collectible.xpm";
	data->relative_path_exit = "/home/eel-garo/Desktop/M.2/so_long/"
		"textures/exit.xpm";
	data->relative_path_floor = "/home/eel-garo/Desktop/M.2/so_long/"
		"textures/space.xpm";
	data->relative_path_enemy = "/home/eel-garo/Desktop/M.2/so_long/"
		"textures/enemy.xpm";
	data->relative_path_exit_open = "/home/eel-garo/Desktop/M.2/so_long/"
		"textures/exit_open.xpm";
	ft_helper_function_int(data);
}

void	ft_free_map(char **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}

int	ft_check_file_map(char *map_ber)
{
	if (!ft_strnstr(map_ber, ".ber", ft_strlen(map_ber)))
		return (0);
	return (1);
}
