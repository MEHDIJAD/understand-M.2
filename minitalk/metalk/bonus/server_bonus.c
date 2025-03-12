/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:09:34 by eel-garo          #+#    #+#             */
/*   Updated: 2025/03/07 17:09:37 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

//* void *context: we need it because the sa_sigaction function pointer in struct sigaction requires it


void	print_bits(unsigned char octet)
{
	int i = 7;

	while (i >= 0)
	{
		char bit;
		if ((octet >> i) & 1)
			bit = '1';
		else
			bit = '0';
		write(1, &bit, 1);
		i--;
	}
}
int ft_count_pointcode(unsigned char *c)
{
	if (*c < 192)
		return (1);
	else if (*c < 224)
		return (2);
	else if (*c < 240)
		return (3);
	else
		return (4);
}

void ft_print(unsigned char *c, int size)
{
	int i = 0;
	while (i < size)
	{
		write(1, &c[i], 1);
		i++;
	}
}

void	ft_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c[4];
	static int	bit, power = 1, pid;
	static int bytes;
	static int size;

	(void)context;
	if (!pid || pid != info->si_pid)
	{
		pid = info->si_pid;
		bytes = 0;
		bit = 0;
		size = 0;
		power = 1;
		for (int i = 0; i < 4; i++) 
			c[i] = 0;
	}
	if (signum == SIGUSR2)
		c[bytes] += power;
	power *= 2;
	bit++;
	if (bit == 8)
	{
		if (c[bytes] == '\0')
			kill(info->si_pid, SIGUSR1);
		if (bytes == 0)
			size = ft_count_pointcode(c);
		bytes++;
		bit = 0;
		power = 1;
		if (bytes == size)
		{
			ft_print(c, size);
			bytes = 0;
			size = 0;
			for (int i = 0; i < 4; i++)
				c[i] = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	ft_printf(1, "server PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause(); //* suspends the process until a signal is received
	}
	return (0);
}

//! it better than just puting a while(1){ }, this will keep the programme running and take resources (CPU)
