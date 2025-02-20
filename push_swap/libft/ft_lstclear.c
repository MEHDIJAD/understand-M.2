/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:31:15 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/20 11:09:43 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_list **stack)
{
	t_list	*node;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		node = (*stack)->next;
		ft_lstdelone(*stack);
		*stack = node;
	}
}
