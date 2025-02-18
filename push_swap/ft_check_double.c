/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:23:05 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/18 13:09:32 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fillarray(int *arr, t_list *list, int size_list)
{
	t_list	*curr;
	int		i;

	i = 0;
	curr = list;
	while (i < size_list && curr != NULL)
	{
		arr[i++] = curr->number;
		curr = curr->next;
	}
}

void	ft_help_function_error(int *arr, t_list **list)
{
	ft_printf(2, "Error\n");
	free(arr);
	ft_lstclear(list);
	exit(1);
}

void	ft_check_double(t_list *list)
{
	int		size_list;
	int		*arr;
	int		i;
	int		j;

	size_list = ft_lstsize(list);
	arr = malloc(sizeof(int) * size_list);
	if (!arr)
		ft_help_function_error(arr, &list); //* in case malloc fail
	ft_fillarray(arr, list, size_list);
	i = 0;
	while (i < size_list)
	{
		j = i + 1;
		while (j < size_list)
		{
			if (arr[i] == arr[j])
				ft_help_function_error(arr, &list);
			j++;
		}
		i++;
	}
	free(arr);
}
