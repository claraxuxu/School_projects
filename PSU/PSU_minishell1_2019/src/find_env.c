/*
** EPITECH PROJECT, 2020
** check_input
** File description:
** check the char we input
*/

#include "../include/my.h"

int loc_list(mini_t *mini, char *env)
{
    mini->nbr = 0;
    for (int i = 0; env[i] != '\0'; i++)
        if (env[i] == ':')
            mini->nbr++;
}
char find_in_env(mini_t *mini)
{
    int j = 0;
    int k = 0;

    for (int i = 0; mini->cp_env[i] != NULL; i++)
        if (mini->cp_env[i][0] == 'P' && mini->cp_env[i][1] == 'A' &&
            mini->cp_env[i][2] == 'T')
            j = i;
    loc_list(mini,mini->cp_env[j]);
    mini->lenv = malloc(sizeof(char*) * mini->nbr + 1);
    for (int i = 0; i <= mini->nbr; i++)
        mini->lenv[i] = malloc(sizeof(char) * 50);
    for (int i = 5,k = 0,a = 0; mini->cp_env[j][i] != '\0'; i++,a++) {
        if (mini->cp_env[j][i] == ':') {
            mini->lenv[k][a] = '\0';
            i++;
            k++;
            a = 0;
        }
        mini->lenv[k][a] = mini->cp_env[j][i];
    }
}
