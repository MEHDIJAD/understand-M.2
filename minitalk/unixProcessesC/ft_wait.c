#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
*! prototype: pid_t wait(int *Wstatus);
* The wait() function in C is used by a parent process
* to wait for one of its child processes to terminate. 
*/
int main(int ac, char **av)
{
    int id = fork();

    if (id == -1)
        perror("fork faild");
    int n;
    if (id == 0)
        n = 1;
    else
        n = 6;
    if (id != 0)
        wait(NULL);
    int i;
    for( i = n; i < n + 5; i++)
    {
        printf("%d ", i);
        fflush(stdout);
    }
    printf("\n");
    return (0);
}

/*
* prototype: int fflush(FILE *stream); \ include <stdio.h>

* MAN (fflush): The fflush() function in C is used to flush the output buffer of a stream, 
* ensuring that any buffered data is written immediately.
*/