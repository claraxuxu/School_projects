/*
** EPITECH PROJECT, 2019
** my_str_is
** File description:
** my_str_is num/alpha
*/

#include "tetris.h"

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

int my_str_isalpha(char *str)
{
    int alpha = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] >= 65 && str[i] <= 90) ||
            (str[i] >= 97 && str[i] <= 122))
            alpha++;
    if (alpha == my_strlen(str))
        return (1);
    return (alpha);
}