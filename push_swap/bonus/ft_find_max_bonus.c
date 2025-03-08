/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_max_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:59:10 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 16:44:35 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
