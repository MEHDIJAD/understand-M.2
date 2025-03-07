#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_sigusr1(int signum)
{
    printf("\nHINT: taking so long man \n");
    fflush(stdout); //* even if we do not use fflush it's enough to put \n
}

int main(int ac, char **av)
{
    int pid = fork();
    if (pid == -1)
    {
        perror("forking failed\n");
        return (-1);
    }
    if (pid == 0) //* child process
    {
        sleep(5);
        //! if we do not sleep the child process it wil execute immediately
        kill(getppid(), SIGUSR1); //* send a SIGUSR1 the the parent process using kill
    }
    else //* (pid != 0), parent process
    {
        struct sigaction sa = {0};
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = handle_sigusr1;
        sigaction(SIGUSR1, &sa, NULL); //* set up a signal hadler to catch SIGUSR1

        int x;
        printf("What is the result of 3 x 5: ");
        scanf("%d", &x); //* stop and wait for the user input 
        //! after 5 second the child process sends the SIGUSR1 signal to the parent
        //* parent process catches signal --> trigger handle_sigusr1 function --> printf("H...
        if (x == 15)
            printf("Right!");
        else
            printf("Wrong?");
        wait(NULL);
    }
    return (0);
}
