
/*
* sigaction struct is used to specify how a process should handle a signal.
* it gives more flexibility compared to signal() function
*/
struct sigaction
{
    void        (*sa_handler)(int); //* Pointer to a signal handler function
    void        (*sa_sigaction)(int, siginfo_t *, void *); //* More advanced signal handler
    sigset_t    sa_mask; //* signal to block while hanling current one
    int         sa_flag; //? modifies behavior of signal handling 
};

/*
* 1- sa_handler: when using simple signal handler, function takes int (the signal number)
* 2- sa_sigaction: Used when SA_SIGINFO is set in sa_flag, provides extra details via siginfo_t.
* 3- sa_mask: Specifies other signals to block
* 4- sa_flag: Flags modifying begavior
*/

//* sigset_t: data type used by POSIX systems to represent a set of signals, allows you to manipulate groups of signals as a single unit.

//* POSIX: (Portable Operating System Interface) is a set of rules that make sure programs work the same way on different Unix-like systems, like Linux and macOS.
 
/*
 * !siginfo_t: is a struct that provides detailed information about a signal that a process receives.
 * it is used when SA_SIGINFO is set in sa_flags
 * it gives extra information like: who sent the signal, cause, and additional data.
*/

typedef struct
{
    int     si_signo; //* signum (SIGUSER1, SIGUSR2)
    int     si_errno; //* Errornum (if signal caused by error)
    int     si_code; //* reason (kernal, user) 
    pid_t   si_pid; //* PID of sender
    uid_t   si_uid; //* user ID of sender
    void    *si_ddr; //* memory address causing fault (like in SIGSEGV)
    int     si_status; //* exit status child process (for SIGCHILD)
    long    si_band; //* band event (for SIGPOLL)
}  siginfo_t;

//* pid_t: data type to store PID in unix-like systems, int or long depend on system
