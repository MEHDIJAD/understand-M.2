/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:38:15 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/20 11:59:44 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_op_rrotate(t_list **stack, char *op) //* last becoms first
{
	t_list	*last;
	t_list	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	second_last = *stack; //* point to head first
	while (second_last->next && second_last->next->next) //* move intell (second_last->next ==> we still have next) && ( second_last->next->next != NULL ==> to stop one befor last)
		second_last = second_last->next; //* to move stack 
	last = second_last->next; //* last point to second last next = last node
	second_last->next = NULL; //* second_last next points to NULL / removing last
	last->next = *stack; //* last next point to head new head 
	*stack = last;
	if (op)
		ft_printf(1, "%s\n", op);
}

/*
* if we have stack: [A] → [B] → [C] → [D] → NULL
* --> second_last = C
* second_last->next = D (which is the last node)
* second_last->next->next = NULL
*/