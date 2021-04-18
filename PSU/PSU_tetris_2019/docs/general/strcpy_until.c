/*
** EPITECH PROJECT, 2020
** counter_functions.c
** File description:
** functions that counts.
*/

#include "tetris.h"

char *strcpy_until(char *str, char until)
{
    int len = strlen_until(str, until);
    char *dest = malloc(sizeof(char) * (len + 1));
    int i = 0;

    for (; str[i] != 0 && str[i] != until; dest[i] = str[i], i++);
    dest[i] = 0;
    return dest;
}
