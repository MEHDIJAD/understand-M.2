/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:04:56 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/20 11:04:29 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstlast(t_list *stack_a)
{
	if (!stack_a)
		return (NULL);
	while (stack_a->next != NULL)
	{
		stack_a = stack_a->next;
	}
	return (stack_a);
}
