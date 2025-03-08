/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_with_arg_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:51:36 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 18:11:27 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_sort_with_arg(t_list **stack_a, t_list **stack_b, char *input)
{
	if (!ft_strncmp(input, "sa\n", 3))
		return (ft_op_swap(stack_a, NULL), 3);
	else if (!ft_strncmp(input, "sb\n", 3))
		return (ft_op_swap(stack_b, NULL), 3);
	else if (!ft_strncmp(input, "ss\n", 3))
		return (ft_op_ss(stack_a, stack_b, NULL), 3);
	else if (!ft_strncmp(input, "pa\n", 3))
		return (ft_op_push(stack_a, stack_b, NULL), 3);
	else if (!ft_strncmp(input, "pb\n", 3))
		return (ft_op_push(stack_b, stack_a, NULL), 3);
	else if (!ft_strncmp(input, "ra\n", 3))
		return (ft_op_rotate(stack_a, NULL), 3);
	else if (!ft_strncmp(input, "rb\n", 3))
		return (ft_op_rotate(stack_b, NULL), 3);
	else if (!ft_strncmp(input, "rr\n", 3))
		return (ft_op_rr(stack_a, stack_b, NULL), 3);
	else if (!ft_strncmp(input, "rra\n", 4))
		return (ft_op_rrotate(stack_a, NULL), 4);
	else if (!ft_strncmp(input, "rrb\n", 4))
		return (ft_op_rrotate(stack_b, NULL), 4);
	else if (!ft_strncmp(input, "rrr\n", 4))
		return (ft_op_rrr(stack_a, stack_b, NULL), 4);
	return (0);
}
