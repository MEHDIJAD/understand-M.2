/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:17:15 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/14 16:33:06 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*current;

	if (!lst)
		return (0);
	size = 0;
	current = lst;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}
