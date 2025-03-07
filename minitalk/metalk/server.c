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

void ft_handler(int signum)
{
    printf("Hi!\n");
}
int main(int ac, char **av)
{
    printf("%d\n", getpid());

    while(1)
    {
        struct sigaction sa = {0};
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = ft_handler;
        sigaction(SIGUSR1, &sa, NULL);
    }
}