/*
** EPITECH PROJECT, 2020
** env_cmp
** File description:
** find env in list for minishell1
*/

#include "my.h"

int env_cmp(char *str1, char *str2, int len)
{
    int i = 0;

    for (i = 0; i < len; i++) {
        if (str1[i] != str2[i])
            return (0);
    }
    if (str1[i] != '=')
        return (0);
    return (1);
}
