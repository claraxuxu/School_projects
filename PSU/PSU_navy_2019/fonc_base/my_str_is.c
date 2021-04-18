/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** task01
*/

#include "../include/my.h"

int my_str_isnum(char str)
{
    int nbr = 0;

    if (str >= 48 && str <= 57)
        nbr++;
    return (nbr);
}

int my_str_isnump(char *str)
{
    int nbr = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 48 && str[i] <= 57)
            nbr++;
    if (nbr == my_strlen(str))
        return (1);
    return (0);
}

int my_str_isalpha(char str)
{
    int alpha = 0;

    if (str >= 65 && str <= 90)
            alpha++;
    return (alpha);
}