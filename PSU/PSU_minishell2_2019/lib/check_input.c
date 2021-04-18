/*
** EPITECH PROJECT, 2020
** check_input
** File description:
** check the char we input
*/

#include "my.h"

int check_input(mini_t *mini)
{
    if (my_strcmp(mini->list[0], "exit") == 0)
        exit(0);
    if (my_strcmp(mini->list[0], "env") == 0) {
        for (int i = 0; mini->cp_env[i] != NULL; i++)
            my_printf("%s\n",mini->cp_env[i]);
        return (1);
    }
    return (0);
}
