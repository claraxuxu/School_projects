/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <string.h>
#include "exec.h"
#include <unistd.h>
#include "input_module.h"

int cmd_pipes(cmd_t const *cmd)
{
    if (cmd == NULL)
        return (0);
    if (strcmp(cmd->op, "|") == 0)
        return (1);
    return (0);
}

int apply_pipes(int fds[2])
{
    if (fds == NULL)
        return (-1);
    if (fds[IN] != -1) {
        dup2(fds[IN], STDOUT_FILENO);
        close(fds[IN]);
    }
    if (fds[OUT] != -1) {
        dup2(fds[OUT], STDIN_FILENO);
        close(fds[OUT]);
    }
    return (0);
}

int reset_io(devt_t val)
{
    int fd = -1;
    int fileno = (val == STD_IN) ? STDIN_FILENO : STDOUT_FILENO;

    if (val == STD_IN)
        fd = open("/dev/stdin", O_RDONLY);
    else
        fd = open("/dev/stdout", O_WRONLY);
    if (fd < 0)
        return (-1);
    dup2(fd, fileno);
    close(fd);
    return (0);
}
