/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_ss_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:14:12 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 16:44:57 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_op_ss(t_list **stack_a, t_list **stack_b, char *op)
{
	ft_op_swap(stack_a, NULL);
	ft_op_swap(stack_b, NULL);
	if (op)
		ft_printf(1, "%s\n", op);
}
