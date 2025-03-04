
#include <signal.h>

//* prototype: int sigemptyset(sigset_t *set);
//* prototype: int sigaddset(sigset_t *set, int signum);

int main(void)
{
    sigset_t signal_set;

    // Initialize an empty signal set
    sigemptyset(&signal_set);

    // Add SIGINT to the signal set
    sigaddset(&signal_set, SIGINT);
}