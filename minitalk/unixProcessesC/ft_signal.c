#include <libc.h>
#include <signal.h>

int main(int ac, char **av)
{
    int pid = fork();
    if (pid == -1)
    {
        perror("fork failed\n");
        return (1);
    }
    if(pid == 0)
    {
        while(1)
        {
            printf("again!?\n");
            usleep(50000);
        }
    }
    else
    {
        sleep(1);
        kill(pid, SIGKILL);
        wait(NULL);
    }
    return (0);
}