#include <libc.h>

int main(int ac, char **av)
{
    int x;
    printf("Input: ");
    scanf("%d", &x);
    printf("Result: %d * 2 = %d\n", x, x * 2);
    return (0);
}
/*
* we use Ctrl+ Z to stop a precess an put in the background
* use fg to give SIGCONT to the process, get pack to front ground
*/