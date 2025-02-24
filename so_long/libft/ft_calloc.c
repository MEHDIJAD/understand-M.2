/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:25:50 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/21 14:25:50 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	all;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	all = count * size;
	ptr = (void *)malloc(all);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (all));
	return (ptr);
}
