/*
** EPITECH PROJECT, 2020
** def_list
** File description:
** prepare list for minishell1
*/

#include "../include/my.h"

void def_env(mini_t *mini, char **env)
{
    int i = 0;
    int b = 0;

    mini->longest = 0;
    for (i = 0; env[i] != NULL; i++)
        if (my_strlen(env[i]) > mini->longest)
            mini->longest = my_strlen(env[i]);
    mini->cp_env = malloc(sizeof(char*) * i + 1);
    for (int a = 0; a < i; a++)
        mini->cp_env[a] = malloc(sizeof(char) * mini->longest + 1);
    for (int a = 0; a < i; a++) {
        for (b = 0; env[a][b] != '\0'; b++)
            mini->cp_env[a][b] = env[a][b];
        mini->cp_env[a][b] = '\0';
    }
}
