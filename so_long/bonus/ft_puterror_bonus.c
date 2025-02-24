/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:28:05 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/21 15:29:52 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_puterror(int error_code)
{
	if (error_code == 1)
		ft_printf(2, "Error\nMap is large. Performance may be affected.\n");
	else if (error_code == 2)
		ft_printf(2, "Error\nincamplit game!");
	else if (error_code == 3)
	{
		ft_printf(2, "Error\n");
		ft_printf(2, "Map has more than one P or E !?, try again!\n");
	}
	else if (error_code == 4)
		ft_printf(2, "Error\nMap has other  components than P,E,C,1,0\n");
	else if (error_code == 5)
		ft_printf(2, "Error\nMap is not Rectangular, try again!\n");
	else if (error_code == 6)
		ft_printf(2, "Error\nMap is not surrounded by walls, try again!\n");
	else if (error_code == 7)
		ft_printf(2, "Error\nMap is not playable, try again!\n");
}
