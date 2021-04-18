/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** cmd_list.c
*/

#include "my.h"

void cmd_list(char *ptr, mini_t *mini, char **env, shell_t *shell)
{
    int pid = 0;

    def_list(ptr, mini);
    if (check_input(mini) == 0) {
        mini->list[mini->argc] = NULL;
        find_in_env(mini);
        pid = fork();
        if (pid == 0) {
            deal_flag(shell);
            for (int i = 0; i < mini->nbr; i++) {
                mini->lenv[i] = my_strcat(my_strcat(mini->lenv[i], "/"),
                                mini->list[0]);
                execve(mini->lenv[i], mini->list, mini->cp_env);
            }
            exit(0);
        }
        else if (pid < 0) exit (0);
        wait(NULL);
    }
}