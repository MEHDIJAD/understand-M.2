/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:12:23 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/20 11:13:14 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_next_min(t_list *lst, int idx)
{
	t_list	*curr;
	t_list	*min_node;

	curr = lst; //* to move in the linked list
	min_node = NULL; //* to set the node with the smallest number 
	while (curr)
	{
		if (curr->index == -1)  //* not indexed yet 
		{
			if (!min_node || curr->number < min_node->number) //* if we still not asigne min to a node we give it the first node OR if it is smaller than the current node ond idex = -1 
				min_node = curr;
		}
		curr = curr->next; //* move to next
	}
	if (min_node) //* if we have a node min result ==> we give it index 
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
