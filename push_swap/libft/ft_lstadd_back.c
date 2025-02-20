/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:03:29 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/20 11:02:31 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_list **stack_a, t_list *new)
{
	if (!stack_a || !new)
		return ;
	if (*stack_a)
		ft_lstlast(*stack_a)->next = new;
	else
		*stack_a = new;
}
