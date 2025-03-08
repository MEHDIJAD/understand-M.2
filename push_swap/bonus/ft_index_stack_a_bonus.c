/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_stack_a_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:12:23 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 16:44:41 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_find_next_min(t_list *lst, int idx)
{
	t_list	*curr;
	t_list	*min_node;

	curr = lst;
	min_node = NULL;
	while (curr)
	{
		if (curr->index == -1)
		{
			if (!min_node || curr->number < min_node->number)
				min_node = curr;
		}
		curr = curr->next;
	}
	if (min_node)
		min_node->index = idx;
}

void	ft_index_stack_a(t_list **stack_a)
{
	int		size_stack;
	int		i;
	int		idx;

	size_stack = ft_lstsize(*stack_a);
	i = 0;
	idx = 0;
	while (i < size_stack)
	{
		ft_find_next_min(*stack_a, idx);
		idx++;
		i++;
	}
}
