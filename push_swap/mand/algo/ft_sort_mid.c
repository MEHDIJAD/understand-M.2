/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:27:05 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/21 18:08:29 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_sort_back(t_list **stack_a, t_list **stack_b)
{
	int		max_place;
	int		mid;

	while (*stack_b)
	{
		mid = ft_lstsize(*stack_b) / 2;
		max_place = ft_find_max(stack_b);
		if (max_place == 0)
			ft_op_push(stack_a, stack_b, "pa");
		else if (max_place <= mid)
		{
			while (max_place--)
				ft_op_rotate(stack_b, "rb");
			ft_op_push(stack_a, stack_b, "pa");
		}
		else if (max_place > mid)
		{
			while (max_place < ft_lstsize(*stack_b))
			{
				ft_op_rrotate(stack_b, "rrb");
				max_place++;
			}
			ft_op_push(stack_a, stack_b, "pa");
		}
	}	
}

static int	ft_special_case(t_list *stack_a)
{
	int		pattern;
	int		i;
	int		temp;

	i = 0;
	pattern = 0;
	temp = stack_a->index;
	while (i < ft_lstsize(stack_a) / 2)
	{
		if (temp > stack_a->index)
			pattern++;
		temp = stack_a->index;
		stack_a = stack_a->next;
		i++;
	}
	if (pattern > (ft_lstsize(stack_a) / 3) + (ft_lstsize(stack_a) / 50))
		return (1);
	return (0);
}

static void	ft_option(t_list **stack_a, int flag)
{
	if (flag == 1)
		ft_op_rrotate(stack_a, "rra");
	else
		ft_op_rotate(stack_a, "ra");
}

void	ft_sort_mid(t_list **stack_a, t_list **stack_b, int range)
{
	int	i;
	int	flag;

	flag = 0;
	if (ft_special_case(*stack_a))
		flag = 1;
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			ft_op_push(stack_b, stack_a, "pb");
			i++;
		}
		else if ((*stack_a)->index <= (i + range))
		{
			ft_op_push(stack_b, stack_a, "pb");
			ft_op_rotate(stack_b, "rb");
			i++;
		}
		else
			ft_option(stack_a, flag);
	}
	ft_sort_back(stack_a, stack_b);
}
