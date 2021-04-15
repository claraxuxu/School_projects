/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** for bsq
*/

#include "include/my.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
