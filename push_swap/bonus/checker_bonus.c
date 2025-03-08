/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:09:25 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 18:10:58 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_correct_arg(char *arg)
{
	const char	*valid_cmds[12];
	int			i;

	valid_cmds[0] = "sa\n";
	valid_cmds[1] = "sb\n";
	valid_cmds[2] = "ss\n";
	valid_cmds[3] = "pa\n";
	valid_cmds[4] = "pb\n";
	valid_cmds[5] = "ra\n";
	valid_cmds[6] = "rb\n";
	valid_cmds[7] = "rr\n";
	valid_cmds[8] = "rra\n";
	valid_cmds[9] = "rrb\n";
	valid_cmds[10] = "rrr\n";
	valid_cmds[11] = NULL;
	i = 0;
	while (valid_cmds[i])
	{
		if (!ft_strncmp(arg, valid_cmds[i], ft_strlen(valid_cmds[i]) + 1))
			return (1);
		i++;
	}
	return (0);
}

static void	ft_help_function(t_list **stack_a, char *input, char *arg)
{
	free(arg);
	free(input);
	ft_lstclear(stack_a);
	ft_printf(2, "Error\n");
	exit(1);
}

static char	*ft_get_argument(t_list **stack_a)
{
	char	*input;
	char	*arg;
	char	*temp;

	input = NULL;
	while (1)
	{
		arg = get_next_line(0);
		if (!arg)
			break ;
		if (!ft_correct_arg(arg))
		{
			get_next_line(-1);
			return (ft_help_function(stack_a, input, arg), NULL);
		}
		temp = ft_strjoined(input, arg);
		free(input);
		input = temp;
		if (!input)
			return (free(arg), NULL);
		free(arg);
	}
	if (arg)
		free(arg);
	return (input);
}

static int	ft_result(t_list **stack_a, t_list **stack_b, char *input)
{
	if (!input)
	{
		if (ft_sorted(*stack_a) && ft_lstsize(*stack_b) == 0)
			return (ft_lstclear(stack_a), ft_printf(1, "OK\n"), 1);
		else
			return (ft_lstclear(stack_a), ft_printf(1, "KO\n"), 1);
	}	
	else if (input)
	{
		while (*input)
			input += ft_sort_with_arg(stack_a, stack_b, input);
	}
	if (ft_sorted(*stack_a) && ft_lstsize(*stack_b) == 0)
		ft_printf(1, "OK\n");
	else
	{
		ft_printf(1, "KO\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*input;
	char	*original_input;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	ft_check_input(av);
	ft_fill_stack_a(av, &stack_a);
	if (!stack_a)
		return (1);
	ft_index_stack_a(&stack_a);
	input = ft_get_argument(&stack_a);
	original_input = input;
	if (!ft_result(&stack_a, &stack_b, input))
		return (ft_lstclear(&stack_a), ft_lstclear(&stack_b),
			free(input), exit(0), 0);
	if (original_input)
		free(original_input);
	ft_lstclear(&stack_a);
}
