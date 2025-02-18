/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:13:26 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/14 17:19:01 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_op_rr(t_list **stack_a, t_list **stack_b, char *op)
{
	ft_op_rotate(stack_a, NULL);
	ft_op_rotate(stack_b, NULL);
	if (op)
		ft_printf(1, "%s\n", op);
}
