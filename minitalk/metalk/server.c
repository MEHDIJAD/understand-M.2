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

void ft_handler(int signum, siginfo_t *info, void *context)
{
    static char c = 0;
    static int bit = 0;
    static int power = 128;
    static int pid;
    if (pid == 0)
        pid = info->si_pid;
    if (pid != info->si_pid)
    {
        pid = info->si_pid;
        c = 0;
        bit = 0;
        power = 128;
    }
    if (signum == SIGUSR2)
        c += power;
    power /= 2; //* move to the next bit
    bit++;
    if (bit == 8)
    {
        if(c == '\0')
            write(1, "\n", 1);
        else
            write(1, &c, 1);
        c = 0;
        bit = 0;
        power = 128; 
    }   
}
int main(int ac, char **av)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.__sigaction_u.__sa_sigaction = ft_handler;
    printf("server PID: %d\n", getpid());
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while(1)
    {
        pause();
    }
    return (0);
}