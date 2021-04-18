/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** task01
*/

#include "../include/my.h"

int my_str_isnum(char const *str)
{
    int nbr = 0;

    if (str == NULL)
        return (0);
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] >= 48 && str[a] <= 57)
            nbr++;
    }
    return (nbr);
}
