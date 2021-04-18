/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** def_list.c
*/

#include "my.h"

void def_list(char *ptr, mini_t *mini)
{
    mini->argc = 0;
    while (*ptr != '\0') {
        if (!my_isspace(*ptr)) {
            mini->list[mini->argc] = ptr;
            mini->argc++;
            while (!my_isspace(*ptr) && *ptr != '\0')
                ptr++;
            *ptr = '\0';
            ptr++;
            continue;
        }
        ptr++;
    }
}