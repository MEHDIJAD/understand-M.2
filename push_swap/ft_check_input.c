/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:00:29 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/18 12:45:28 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check(char *str)
{
	int	i;
	int	space;
	int	error;

	i = 0;
	space = 1; //* flag variable, assuming we have spaces 1 = true
	error = 0; //* assuming we do not have error = false
	while (str[i])
	{
		if (str[i] != ' ') //* if we do not have a space at a position we make the flag as false, if all spaces in an argement we get space flag all spaces stay true
			space = 0; 
		if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1])) //* if char sign and after it not digit 
			error = 1;
		else if (i > 0 && (str[i] == '+' || str[i] == '-') && str[i - 1] != ' ') //* if number are mixed +1-1 
			error = 1;
		if (!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-'
			&& str[i] != ' ') //* if not digit, and not sign +/-
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
