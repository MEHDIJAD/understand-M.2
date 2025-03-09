#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int); //* Typedef signal handler pointer function

void handler_sigint(int signum)
{
    printf("SIGINT received. Exiting...\n");
    exit(0);
}
int main()
{
    sighandler_t handler;
    handler = handler_sigint;
    if (signal(SIGINT, handler) == SIG_ERR)
    {
        perror("signal");
        return (1);
    }
    while(1)
    {
        pause();
    }
    return (0);
}