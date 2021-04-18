/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_strcmp.c
*/

#include "defender.h"

int my_strcmp(char *s, char *str)
{
    int start = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (s[i] != str[i])
            start++;
    }
    if (start == 0)
        return (0);
    else
        return (1);
}

int my_have(char *str, char a)
{
    int start = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == a) {
            start++;
        }
    }
    return (start);
}

int my_str_isnum(char *str)
{
    int nbr = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 48 && str[i] <= 57)
            nbr++;
    if (nbr == my_strlen(str))
        return (1);
    return (0);
}

int my_getnbr(char *str)
{
    int val = 0;

    while (*str) {
        if (*str >= '0' && *str <= '9') {
            val *= 10;
            val += *str - '0';
        } else return (-1);
        str++;
    }
    return (val);
}