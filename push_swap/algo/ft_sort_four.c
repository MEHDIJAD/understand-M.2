/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:48:22 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/08 15:20:57 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	int		min;

	min = ft_find_min_place(stack_a);
	if (min < 2)
	{
		if (min == 1)
			ft_op_swap(stack_a, "sa");
	}
	else if (min == 2)
	{
		ft_op_rrotate(stack_a, "rra");
		ft_op_rrotate(stack_a, "rra");
	}
	else if (min == 3)
		ft_op_rrotate(stack_a, "rra");
	ft_op_push(stack_b, stack_a, "pb");
	ft_sort_three(stack_a);
	ft_op_push(stack_a, stack_b, "pa");
}
