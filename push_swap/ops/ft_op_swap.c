/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:55:31 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/20 11:49:52 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_op_swap(t_list **stack, char *op)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next) //* at least two element
		return ;
	first = *stack; //* first point to head
	second = (*stack)->next; //* second point to one after head
	first->next = second->next; //* first next points to second next , 3er node 
	second->next = first; //* second next becoms fisrt to swap 
	*stack = second; //* second is the new head
	if (op)
		ft_printf(1, "%s\n", op);
}
