#include <libc.h>

void signal_handel(int signum)
{
    if (signum == SIGUSR1)
    {
        printf("Hello!\n");
    }
    else if (signum == SIGUSR2)
    {
          printf("random: %d\n", rand());
    }
}

int main()
{
    sigaction(SIGUSR1, &signal_handel, NULL);
    sigaction(SIGUSR2, &signal_handel, NULL);
}