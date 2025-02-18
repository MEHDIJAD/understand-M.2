/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:14:28 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/18 12:47:40 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_spaces(const char *str)
{
	int	spa;

	spa = 0;
	while ((str[spa] >= 9 && str[spa] <= 13) || str[spa] == 32)
		spa++;
	return (spa);
}

static int	ft_sign(const char *str, int *i)
{
	int	signe;

	signe = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			signe = -1;
		(*i)++;
	}
	return (signe);
}

long	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	long				number;
	int					digit;

	i = ft_spaces(str);
	sign = ft_sign(str, &i);
	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		number = (number * 10) + digit;
		i++;
	}
	return ((number * sign));
}
