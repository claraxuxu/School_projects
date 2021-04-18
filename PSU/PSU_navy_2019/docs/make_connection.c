/*
** EPITECH PROJECT, 2019
** make_connection
** File description:
** make connection between two terminals
*/

#include "my.h"

void receive(int sig)
{
    my_printf("sucessfully connected\n\n");
}

void signal_handler(int sig, siginfo_t *sig_info, void *context)
{
    if (sig == SIGUSR1)
        kill(sig_info->si_pid, sig);
    id2 = sig_info->si_pid;
    my_printf("enemy connected\n\n");
}
int make_connection_sec(file_t *file, char **av)
{
    signal(SIGUSR1, &receive);
    if (kill(my_atoistr(av[1]), SIGUSR1) == -1)
        return (-1);
    file->id1 = my_atoistr(av[1]);
    file->id2 = getpid();
    pause();
    return (0);
}
int make_connection(file_t *file, char **av)
{
    struct sigaction sig;
    pid_t a = getpid();

    my_printf("my_pid: %i\n",a);
    if (file->ac == 2) {
        file->id1 = getpid();
        my_printf("waiting for enemy connection...\n\n");
        sigemptyset(&sig.sa_mask);
        sig.sa_flags = SA_SIGINFO;
        sig.sa_sigaction = &signal_handler;
        sigaction(SIGUSR1, &sig, NULL);
        pause();
        file->id2 = id2;
    }
    if (file->ac == 3)
        if (make_connection_sec(file,av) == -1)
            return (-1);
}
