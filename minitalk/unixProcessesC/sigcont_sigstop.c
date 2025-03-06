#include <libc.h>

int main(int ac, char **av)
{
    int pid = fork();

    if (pid == -1)
    {
        perror("forking failed\n");
        return (1);
    }
    if (pid == 0)
    {
        while(1)
        {
            printf("again!\n");
            usleep(50000);
        }
    }
    else
    {
        kill(pid, SIGSTOP);
        int time;
        do {
                printf("Time in second for execution: ");
                scanf("%d", &time);
                if (time > 0)
                {
                    kill(pid, SIGCONT);
                    sleep(time);
                    kill(pid, SIGSTOP);
                }
        } while (time > 0);
        
        kill(pid, SIGKILL);
        wait(NULL);
    }
}