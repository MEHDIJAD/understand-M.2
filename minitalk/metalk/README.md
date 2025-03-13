Minitalk - Communication Protocol Using Signals
MinTalk is a communication protocol that involves sending messages between two processes using only SIGUSR1 and SIGUSR2.

Overview
pgsql
Copy
Edit
        +-------------------+
        |  Speaker / Client |
        |                   | -----> Signal / Message
        +-------------------+
                              |
        +-------------------+ |
        | Listener / Server |
        +-------------------+
Key Concepts
Process: A program that is running.
Signal: A form of communication between processes used by Unix-like systems.
It can be considered as a message or event.
When a process receives a signal, it will stop and take action based on that signal.
Why MinTalk Uses Signals
In MinTalk, we cannot directly send entire strings through signals. Instead, the message is divided into bytes and bits, and each bit or byte is sent using signals.

To send a signal to a process, we need its PID (Process ID).

Functions Used
signal()
Prototype: sighandler_t signal(int signum, sighandler_t handler);
This function sets a signal handler to be called when a specific signal is received by a running program.

signum: The signal to handle, such as SIGINT, SIGTERM, SIGUSR1, SIGUSR2, etc.
handler: The function to call when the signal is received.
kill()
Prototype: int kill(pid_t pid, int sig);
Sends a signal to a specific process by its PID.

get_pid()
Retrieves the PID of the current process.

