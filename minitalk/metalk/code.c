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

void ft_handelOneChar (int c)
{
    int *arr;
    int i = 0;

    arr = malloc(sizeof(int) * 8);
    while (c > 0)
    {
        if (c % 2 == 0)
            arr[i] = 0;
        else if (c % 2 == 1)
            arr[i] = 1;
        c /= 2;
        i++;
    }
    for(int j = 8; j >= 0; j--)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");
}
void ft_sendmessage(char *argv)
{
    while(*argv)
    {
        ft_handelOneChar(*argv);
        argv++;
    }
}

int main(int ac, char **av)
{
    int i;
    int pid;

    if (ac == 3)
    {
        pid = atoi(av[1]);
        ft_sendmessage(av[2]);
    }
    else
        return (1);
}