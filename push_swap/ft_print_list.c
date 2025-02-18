/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:40:01 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/14 16:26:11 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print(t_list *stack, char c)
{
	t_list	*current;

	current = stack;
	while (current != NULL)
	{
		ft_printf(1, "%d ", current->number);
		ft_printf(1, "%d\n", current->index);
		current = current->next;
	}
	ft_printf(1, "---\n");
	ft_printf(1, "%c\n\n", c);
}

void	ft_print_list(t_list *stack_a, t_list *stack_b, char a, char b)
{
	ft_print(stack_a, a);
	ft_print(stack_b, b);
}
