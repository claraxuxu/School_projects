/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** count number of string
*/

#include "tetris.h"

int my_strlen(char const *str)
{
    int a;

    if (str == NULL)
        return 0;
    for (a = 0; str[a] != 0; a++);
    return (a);
}
