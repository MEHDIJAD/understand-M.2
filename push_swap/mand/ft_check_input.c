/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:00:29 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/14 17:28:44 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check(char *str)
{
	int	i;
	int	space;
	int	error;

	i = 0;
	space = 1;
	error = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			space = 0;
		if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
			error = 1;
		else if (i > 0 && (str[i] == '+' || str[i] == '-') && str[i - 1] != ' ')
			error = 1;
		if (!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-'
			&& str[i] != ' ')
			error = 1;
		i++;
	}
	if (error || space)
	{
		ft_printf(2, "Error\n");
		exit(1);
	}
}

void	ft_check_input(char *av[])
{
	int	i;

	i = 1;
	while (av[i] != NULL)
		ft_check(av[i++]);
}
