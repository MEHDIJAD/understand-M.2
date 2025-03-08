/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:10:44 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 15:04:47 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_setup_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_free_map(data->ptr), 0);
	data->win = mlx_new_window(data->mlx,
			(data->y * IMAGE_SIZE), (data->x * IMAGE_SIZE), "so_long");
	if (!data->win)
		return (ft_cleanup_game(data), 0);
	return (1);
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac != 2)
		return (ft_printf(2, "Error\nWrong number of arguments!?"), 0);
	ft_init_data(&data);
	if (!ft_check_file_map(av[1]))
		return (ft_printf(2, "Error\nfile name do not end with .ber!"),
			EXIT_FAILURE);
	if (!ft_get_map(av[1], &data))
		return (EXIT_FAILURE);
	if (!ft_get_map_dimention(&data))
		return (EXIT_FAILURE);
	if (!ft_valid_map(&data))
		return (ft_free_map(data.ptr), EXIT_FAILURE);
	ft_enemy_count(&data);
	if (!ft_setup_mlx(&data))
		return (EXIT_FAILURE);
	ft_get_img_data(&data);
	ft_drow_map(&data);
	ft_get_enemy_positions(&data);
	mlx_loop_hook(data.mlx, ft_moving_enemy, &data);
	mlx_hook(data.win, 2, 1, ft_first_move, &data);
	mlx_hook(data.win, 17, 0, ft_exit, &data);
	mlx_loop(data.mlx);
	return (0);
}
