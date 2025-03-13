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

#include "minitalk.h"

//* void *context: we need it because the sa_sigaction function pointer in struct sigaction requires it

void	ft_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = 0, power = 128, pid = 0;

	(void)context;
	if (!pid || pid != info->si_pid)
	{
		pid = info->si_pid;
		c = 0;
		bit = 0;
		power = 128;
	}
	if (signum == SIGUSR2)
		c += power;
	power /= 2;
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		bit = 0;
		power = 128;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	ft_printf(1, "server PID: %d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (ft_printf(2, "sigaction failed\n"), 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf(2, "sigaction failed\n"), 1);
	while (1)
	{
		pause(); //* suspends the process until a signal is received
	}
	return (0);
}

//! it better than just puting a while(1){ }, this will keep the programme running and take resources (CPU)
