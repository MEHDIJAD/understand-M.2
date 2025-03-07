#include <libc.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int server_pid = atoi(av[1]);
        kill(server_pid, SIGUSR1);
        kill(server_pid, SIGUSR2);
    }

}
