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

#include "minitalk_bonus.h"

void	ft_handelonechar(unsigned int c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c % 2 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		usleep(200);
		c /= 2;
		i++;
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

void	signal_hanfler(int signum)
{
	(void)signum;
	ft_printf(1, "\nmessage received\n");
}
int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0) //? do i need to handle pid == 0 on it on 
		{
			write(1, "Invalid PID", 12);
			exit(1);
		}
		signal(SIGUSR1, signal_hanfler); //add
		ft_sendmessage(av[2], pid);
	}
	else
	{
		write(2, "Usage: ./client <PID> <message>\n", 32);
		return (1);
	}
	return (0);
}
