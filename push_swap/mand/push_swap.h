/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:11:11 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 16:37:26 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

# define BUFFER_SIZE 1000

# define OPEN_MAX 1024

void	ft_check_input(char *av[]);
void	ft_fill_stack_a(char **vic, t_list **list);
void	ft_check_double(t_list *list);
void	ft_index_stack_a(t_list **lst);
void	ft_sort_list(t_list **stack_a, t_list **stack_b);
int		ft_sorted(t_list *stack_a);
void	ft_op_swap(t_list **stack, char *op);
void	ft_op_rotate(t_list **stack, char *op);
void	ft_op_rrotate(t_list **stack, char *op);
void	ft_op_push(t_list **stack_dst, t_list **stack_src, char *op);
void	ft_sort_three(t_list **stack_a);
void	ft_sort_four(t_list **stack_a, t_list **stack_b);
void	ft_sort_five(t_list **stack_a, t_list **stack_b);
void	ft_sort_mid(t_list **stack_a, t_list **stack_b, int range);
void	ft_op_rrr(t_list **stack_a, t_list **stack_b, char *op);
void	ft_op_rr(t_list **stack_a, t_list **stack_b, char *op);
void	ft_op_ss(t_list **stack_a, t_list **stack_b, char *op);
int		ft_sort_with_arg(t_list **stack_a, t_list **stack_b, char *input);
int		ft_find_min_place(t_list **stack);
int		ft_find_max(t_list **stack);
char	*get_next_line(int fd);
char	*ft_read_join(char **str_buff, int fd);
char	*ft_get_line(char **str_buf);
int		ft_len_to_newline(char *str_buf);
int		ft_found_newline(char *str_buf);
char	*get_next_line(int fd);

#endif