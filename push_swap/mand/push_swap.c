/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:13:21 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/18 11:24:39 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	ft_check_input(av);
	ft_fill_stack_a(av, &stack_a);
	if (!stack_a)
		return (1);
	ft_index_stack_a(&stack_a);
	ft_sort_list(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
}
