/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:54:29 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 16:44:38 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_find_min_place(t_list **stack)
{
	t_list	*curr;
	int		min;
	int		min_index;
	int		i;

	curr = *stack;
	min = curr->number;
	min_index = 0;
	i = 0;
	while (curr)
	{
		if (curr->number < min)
		{
			min = curr->number;
			min_index = i;
		}
		i++;
		curr = curr->next;
	}
	return (min_index);
}
