/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** other_cmd.c
*/

#include "my.h"

void other_cmd(mini_t *mini)
{
    if (!my_strcmp(mini->list[0], "cd"))
        in_cd(mini);
    else if (!my_strcmp(mini->list[0], "setenv"))
        exit (0);
    else if (!my_strcmp(mini->list[0], "unsetenv"))
        return;
}