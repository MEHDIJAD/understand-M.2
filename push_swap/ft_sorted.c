/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:26:19 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/14 16:28:32 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_list *stack_a)
{
	t_list	*curr;

	if (!stack_a)
		return (0);
	curr = stack_a;
	while (curr->next)
	{
		if (curr->number > curr->next->number)
			return (0);
		curr = curr->next;
	}
	return (1);
}
