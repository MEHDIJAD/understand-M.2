#include <stdio.h>
#include <signal.h>

//* prototype: sighandler_t signal(int signum, sighandler_t handler);

void signal_handler(int signum)
{
    printf("Received SIGNAL %d!\n", signum);
    exit(0);
}
int main()
{
    signal(SIGINT, signal_handler);
    while (1){
    }
    return (0);
}