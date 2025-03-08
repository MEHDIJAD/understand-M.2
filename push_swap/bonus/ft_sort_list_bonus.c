/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:29:14 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 16:45:10 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_sort_two(t_list **stack_a)
{
	int	first;
	int	second;

	if (!stack_a)
		return ;
	first = (*stack_a)->number;
	second = (*stack_a)->next->number;
	if (first > second)
		ft_op_swap(stack_a, "sa");
}

void	ft_sort_list(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	range;

	if (ft_sorted(*stack_a))
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		ft_sort_two(stack_a);
	else if (size <= 3)
		ft_sort_three(stack_a);
	else if (size <= 4)
		ft_sort_four(stack_a, stack_b);
	else if (size <= 5)
		ft_sort_five(stack_a, stack_b);
	else if (size <= 100)
	{
		range = 11;
		ft_sort_mid(stack_a, stack_b, range);
	}
	else if (size > 100)
	{
		range = 34;
		ft_sort_mid(stack_a, stack_b, range);
	}
}
