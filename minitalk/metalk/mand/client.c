/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:09:29 by eel-garo          #+#    #+#             */
/*   Updated: 2025/03/07 17:09:31 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handelonechar(int c, int pid)
{
	int	bits[8];
	int	i;

	i = 0;
	while (i < 8)
	{
		bits[i] = c % 2;
		c /= 2;
		i++;
	}
	while (--i >= 0)
	{
		if (bits[i] == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (ft_printf(2, "kill failed\n"), exit(1));
		}
		else
			if (kill(pid, SIGUSR2) == -1)
				return (ft_printf(2, "kill failed\n"), exit(1));
		usleep(200);
		usleep(200);
	}
}

void	ft_sendmessage(char *argv, int pid)
{
	while (*argv)
	{
		ft_handelonechar(*argv, pid);
		argv++;
	}
	ft_handelonechar('\0', pid);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			write(2, "Invalid PID", 12);
			exit(1);
		}
		ft_sendmessage(av[2], pid);
	}
	else
	{
		write(2, "Usage: ./client <PID> <message>\n", 32);
		return (1);
	}
	return (0);
}
