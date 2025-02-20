/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:21:54 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/20 11:41:52 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_op_rotate(t_list **stack, char *op) //* the first element becoms the last
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next) //* !(*stack)->next = the stack have to have (hhh) at least two element
		return ;
	first = *stack; //* first points to head
	*stack = (*stack)->next; //* move stack one node
	first->next = NULL; //* dettach first node form stack
	last = *stack; //* last point new node / second node (so we can move thgou stack to add first at the end)
	while (last->next)
		last = last->next;
	last->next = first; //* add first at the end 
	if (op)
		ft_printf(1, "%s\n", op);
}
