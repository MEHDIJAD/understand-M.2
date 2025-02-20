/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:10:52 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/20 11:33:52 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_op_push(t_list **stack_dst, t_list **stack_src, char *op)
{
	t_list	*temp;

	if (!stack_src || !*stack_src) //*if stack_src itself is NULL OR if *"if stack_src is NULL" (meaning the source stack has no elements)
		return ;
	temp = *stack_src; //* temp point to head of source
	*stack_src = (*stack_src)->next; //* move head to next node in stack
	temp->next = *stack_dst; //* temp next point to head of dest
	*stack_dst = temp; //* dest point to new head = temp
	if (op)
		ft_printf(1, "%s\n", op);
}
//* we do not need to add a condition for stack_dest
