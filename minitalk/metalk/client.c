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

void ft_handelOneChar (int c, int pid)
{
    int bits[8];
    int i = 0;
    while (i < 8) //* loop 
    {
        bits[i] = c % 2;
        c /= 2;
        i++;
    }
    while (--i >= 0)
    {
        if (bits[i] == 0) //* for 0
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2); //* for 1
        usleep(200);
        usleep(200);
    }
}

void ft_sendmessage(char *argv, int pid)
{
    while(*argv)
    {
        ft_handelOneChar(*argv, pid);
        argv++;
    }
    ft_handelOneChar('\0', pid);
}

int main(int ac, char **av)
{
    int i;
    int pid;

    if (ac == 3)
    {
        pid = atoi(av[1]);
        if (pid <= 0)
            printf("Invalid PID");
        ft_sendmessage(av[2], pid);
    }
    else
    {
        write(2, "Usage: ./client <PID> <message>\n", 32);
        return (1);
    }
    return (0);
}