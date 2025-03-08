/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack_a_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:12:12 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 16:44:31 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_fill(char *av, t_list **stack_a)
{
	int		i;
	long	number;

	i = 0;
	while (av[i])
	{
		while (av[i] == ' ')
			i++;
		if (ft_isdigit(av[i]) || av[i] == '+' || av[i] == '-')
		{
			number = ft_atoi(&av[i]);
			if (number > INT_MAX)
			{
				ft_printf(2, "Error\n");
				ft_lstclear(stack_a);
				exit(1);
			}
			ft_lstadd_back(stack_a, ft_lstnew(number));
		}
		while (ft_isdigit(av[i]) || av[i] == '+' || av[i] == '-')
			i++;
	}
}

void	ft_fill_stack_a(char **vic, t_list **stack_a)
{
	int	i;

	i = 1;
	while (vic[i] != NULL)
		ft_fill(vic[i++], stack_a);
	ft_check_double(*stack_a);
}
