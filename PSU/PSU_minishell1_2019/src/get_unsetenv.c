/*
** EPITECH PROJECT, 2020
** get_unsetenv
** File description:
** setenv list for minishell1
*/

#include "../include/my.h"

void del_env(mini_t *mini, int i)
{
    int j = i;
    char *copy = malloc(sizeof(char) * mini->longest);

    for (j = i; mini->cp_env[j] != NULL; j++);
    for (int k = i; k < j - 1; k++) {
        copy = mini->cp_env[k + 1];
        mini->cp_env[k] = copy;
        copy = NULL;
    }
    mini->cp_env[j - 1] = NULL;
}
void get_unsetenv(mini_t *mini)
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
        if (env_cmp(mini->cp_env[i], mini->list[1], len) == 1)
            del_env(mini, i);
        else k++;
    }
    if (k >= j)
        mini->cp_env[i] = NULL;
}
