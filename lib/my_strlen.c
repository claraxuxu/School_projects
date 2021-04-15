/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** count number of string
*/

#include "include/my.h"

int my_strlen(char const *str)
{
    int a = 0;

    for (; str[a]; a++);
    return (a);
}
