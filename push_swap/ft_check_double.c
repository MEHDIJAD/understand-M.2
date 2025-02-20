/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:23:05 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/20 11:08:35 by eel-garo         ###   ########.fr       */
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

static void	ft_help_function_error(int *arr, t_list **list)
{
	ft_printf(2, "Error\n");
	free(arr);
	ft_lstclear(list);
	exit(1);
}

void	ft_check_double(t_list *stack_a)
{
	int		size_stack;
	int		*arr;
	int		i;
	int		j;

	size_stack = ft_lstsize(stack_a);
	arr = malloc(sizeof(int) * size_stack);
	if (!arr)
		ft_help_function_error(arr, &stack_a); //* in case malloc fail
	ft_fillarray(arr, stack_a, size_stack);
	i = 0;
	while (i < size_stack)
	{
		j = i + 1;
		while (j < size_stack)
		{
			if (arr[i] == arr[j])
				ft_help_function_error(arr, &stack_a);
			j++;
		}
		i++;
	}
	free(arr);
}
