/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoined.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:07:56 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/14 16:40:20 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*ft_filljoin(char *tofill, const char *str_buf, const char *buf)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str_buf[i])
	{
		tofill[i] = str_buf[i];
		i++;
	}
	j = 0;
	while (buf[j])
	{
		tofill[i] = buf[j];
		i++;
		j++;
	}
	tofill[i] = '\0';
	return (tofill);
}

char	*ft_strjoined(char const *str_buff, char const *buf)
{
	char	*strjn;
	size_t	len;

	if (!str_buff && !buf)
		return (NULL);
	if (!str_buff)
		return (ft_strdup(buf));
	if (!buf)
		return (ft_strdup(str_buff));
	len = ft_strlen(str_buff) + ft_strlen(buf);
	strjn = malloc((len + 1) * sizeof(char));
	if (!strjn)
		return (NULL);
	strjn = ft_filljoin(strjn, str_buff, buf);
	return (strjn);
}
