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


void	ft_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = 0, power = 1, pid = 0;

	(void)context;
	if (!pid || pid != info->si_pid)
	{
		pid = info->si_pid;
		c = 0;
		bit = 0;
		power = 1;
	}
	if (signum == SIGUSR2)
		c += power;
	power *= 2;
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			// write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
			write(1, &c, 1);
		c = 0;
		bit = 0;
		power = 1;
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
