#include <stdio.h>
#include <signal.h>
#include <unistd.h>


int main(void)
{
    pid_t pid = getpid(); //* get the precess ID of the current process
    int result; //* send the SIGKILL signal to the process

    result = kill(pid, SIGKILL);
    if (result == 0)
        printf("Process terminated successfully.\n");
    else
        printf("Error terminating process.\n");
    return (0);
}