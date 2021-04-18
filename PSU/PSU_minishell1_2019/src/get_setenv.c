/*
** EPITECH PROJECT, 2020
** get_setenv
** File description:
** setenv list for minishell1
*/

#include "../include/my.h"

void change_env(mini_t *mini, int i)
{
    mini->cp_env[i] = NULL;
    mini->cp_env[i] = my_strcat(my_strcat(mini->list[1], "="),
                                mini->list[2]);
}
void get_setenv(mini_t *mini)
{
    int cmd = 0;
    int len = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    for (cmd = 0; mini->list[cmd] != NULL; cmd++);
    len = my_strlen(mini->list[1]);
    for (j = 0; mini->cp_env[j] != NULL; j++);
    for (i = 0; mini->cp_env[i] != NULL; i++) {
        if (env_cmp(mini->cp_env[i],mini->list[1],len) == 1)
            change_env(mini, i);
        else k++;
    }
    if (k >= j)
        change_env(mini, i);
}
