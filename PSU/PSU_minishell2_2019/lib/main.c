/*
** EPITECH PROJECT, 2020
** main
** File description:
** minishell1
*/

#include "my.h"

void deal_flag(shell_t *shell)
{
    int fd = 0;

    if (shell->flag == 1) {
        fd = open(shell->redi_cmd, O_CREAT | O_WRONLY | O_TRUNC, 0664);
        dup2(fd, 1);
    } else if (shell->flag == 2) {
        fd = open(shell->redi_cmd, O_CREAT | O_WRONLY | O_APPEND, 0664);
        dup2(fd, 1);
    }
}

char *get_cmd_line(char *tmp)
{
    size_t len1 = 0;
    ssize_t nread = 0;
    nread = getline(&tmp, &len1, stdin);
    if (nread == -1) {
        my_printf("exit\n");
        exit (0);
    }
    return (tmp);
}

int main(int ac, char **av, char **env)
{
    char *tmp = NULL;
    char *ptr = NULL;

    mini_t mini;
    shell_t shell;
    init_struct(&mini, &shell);
    def_env(&mini, env);
    while (1) {
        print_prompt();
        tmp = get_cmd_line(tmp);
        ptr = tmp;
        analyse_cmd(&shell, ptr);
        ptr = tmp;
        cmd_list(ptr, &mini, env, &shell);
        other_cmd(&mini);
        shell.flag = 0;
        shell.redi_cmd = NULL;
    }
    return (0);
}