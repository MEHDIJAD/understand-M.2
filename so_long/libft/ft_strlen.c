/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:29:56 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/21 14:29:56 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *buf)
{
	size_t	len;

	if (!buf)
		return (0);
	len = 0;
	while (buf[len])
		len++;
	return (len);
}
