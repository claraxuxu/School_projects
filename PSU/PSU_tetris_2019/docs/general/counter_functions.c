/*
** EPITECH PROJECT, 2020
** counter_functions.c
** File description:
** functions that counts.
*/

#include "tetris.h"

int count_that_lines(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return (i);
}

int strlen_until(char *str, char until)
{
    int i = 0;

    if (str == NULL)
        return (i);
    for (; str[i] != 0 && str[i] != until; i++);
    return (i);
}

int count_that_char(char *str, char c)
{
    int count = 0;

    if (str == NULL)
        return (count);
    for (int i = 0; str[i] != 0; i++)
        if (str[i] == c)
            count++;
    return (count);
}
