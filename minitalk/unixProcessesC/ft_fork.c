#include <unistd.h>
#include <stdio.h>

/*
*! prototype:pid_t fork(void);
* fork() causes creation of a new process.  
* The new process (child process) is an exact copy of the
    * calling process (parent process) except for the following:
    !The child process has a unique process ID.
    *
*/
int main(int ac, char **av)
{
    int id = fork();
    //* forking process
    printf("Hello! from ID: %d\n", id);
    //* if we do :
    if (id == 0)
        printf("hello from the child process\n");
    else
        printf("hello from the parent process\n");
    //* we get the two statement!?
    //! so after the line of fork the code will execute for bouth child and parent process
    return (0);
}

/*
* OUTPUT: *Hello! from ID: 79555 parent process
          *Hello! from ID: 0 child process
*/