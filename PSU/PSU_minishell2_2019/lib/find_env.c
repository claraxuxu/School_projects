/*
** EPITECH PROJECT, 2020
** check_input
** File description:
** check the char we input
*/

#include "../include/my.h"

void loc_list(mini_t *mini, char *env)
{
    mini->nbr = 0;
    for (int i = 0; env[i] != '\0'; i++)
        if (env[i] == ':')
            mini->nbr++;
}

void find_in_env(mini_t *mini)
{
    int j = 0;
    int k = 0;

    for (int i = 0; i < mini->i; i++)
        if (my_strncmp(mini->cp_env[i], "PATH=", 5) == 0)
            j = i;
    loc_list(mini, mini->cp_env[j]);
    mini->lenv = malloc(sizeof(char*) * mini->nbr + 1);
    for (int i = 0; i <= mini->nbr; i++)
        mini->lenv[i] = malloc(sizeof(char) * 50);
    for (int i = 5, a = 0; mini->cp_env[j][i] != '\0'; i++, a++) {
        if (mini->cp_env[j][i] == ':') {
            mini->lenv[k][a] = '\0';
            i++;
            k++;
            a = 0;
        }
        mini->lenv[k][a] = mini->cp_env[j][i];
    }
}
