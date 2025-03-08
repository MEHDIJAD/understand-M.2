/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:03:16 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/18 13:21:50 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = ft_find_min_place(stack_a);
	if (min == 1)
		ft_op_swap(stack_a, "sa");
	else if (min == 2)
	{
		ft_op_rotate(stack_a, "ra");
		ft_op_rotate(stack_a, "ra");
	}
	else if (min == 3)
	{
		ft_op_rrotate(stack_a, "rra");
		ft_op_rrotate(stack_a, "rra");
	}
	else if (min == 4)
		ft_op_rrotate(stack_a, "rra");
	ft_op_push(stack_b, stack_a, "pb");
	ft_sort_four(stack_a, stack_b);
	ft_op_push(stack_a, stack_b, "pa");
}
