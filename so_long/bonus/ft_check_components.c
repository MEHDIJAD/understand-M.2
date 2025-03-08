/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_components.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:36:43 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 14:40:24 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_parsing(t_data *data, t_param *param)
{
	int	i;
	int	j;

	*param = (t_param){0};
	i = 0;
	while (data->ptr[++i])
	{
		j = 0;
		while (data->ptr[i][j])
		{
			if (data->ptr[i][j] == 'P')
				param->player = true;
			if (data->ptr[i][j] == 'C')
				param->collact = true;
			if (data->ptr[i][j] == 'E')
				param->exit = true;
			if (data->ptr[i][j] == '0')
				param->space = true;
			if (data->ptr[i][j] == '1')
				param->wall = true;
			if (data->ptr[i][j] == 'T')
				param->enemy = true;
			j++;
		}
	}
}

int	ft_check_components(t_data *data)
{
	t_param	param;

	ft_parsing(data, &param);
	return (param.player && param.collact && param.exit
		&& param.space && param.wall && param.enemy);
}
