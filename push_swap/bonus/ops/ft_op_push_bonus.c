/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_push_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:10:52 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 17:43:49 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_op_push(t_list **stack_dst, t_list **stack_src, char *op)
{
	t_list	*temp;

	if (!stack_src || !*stack_src)
		return ;
	temp = *stack_src;
	*stack_src = (*stack_src)->next;
	temp->next = *stack_dst;
	*stack_dst = temp;
	if (op)
		ft_printf(1, "%s\n", op);
}
