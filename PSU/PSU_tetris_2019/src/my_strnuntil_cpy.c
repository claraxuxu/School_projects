/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** my_strnuntil_cpy.c
*/

#include "tetris.h"

char *my_strnuntil_cpy(char *str, int n)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) - n + 1));
    int i = 0;

    if (str == NULL || n < 0 || n > my_strlen(str))
        return NULL;
    for (; str[i] != 0 && i < n; dest[i] = str[i], i++);
    dest[i] = 0;
    return dest;
}
