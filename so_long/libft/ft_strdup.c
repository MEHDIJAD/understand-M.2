/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:29:08 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/21 14:29:08 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*cpy;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	cpy = malloc(sizeof(char) * (size + 1));
	if (!cpy)
		return (NULL);
	ft_memcpy(cpy, s1, size);
	cpy[size] = '\0';
	return (cpy);
}
