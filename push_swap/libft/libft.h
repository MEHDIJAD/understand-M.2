/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <eel-garo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:01:39 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/28 17:10:08 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{	
	int				number;
	int				index;
	struct s_list	*next;
}		t_list;

long	ft_atoi(const char *str);
int		ft_isdigit(int c);
t_list	*ft_lstnew(int number);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **stack, t_list *new);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
char	*ft_strjoined(char const *s1, char const *s2);

#endif