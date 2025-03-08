/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:59:10 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/14 16:21:51 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(t_list **stack)
{
	t_list	*curr;
	int		max;
	int		max_index;
	int		i;

	if (!stack || !*stack)
		return (-1);
	curr = *stack;
	max = curr->number;
	max_index = 0;
	i = 0;
	while (curr)
	{
		if (curr->number > max)
		{
			max = curr->number;
			max_index = i;
		}
		i++;
		curr = curr->next;
	}
	return (max_index);
}
