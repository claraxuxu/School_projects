/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** my_realloc.c
*/

#include "defender.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int c = 0;
    while (c < n) {
        dest[c] = src[c];
        c++;
    }
    return (dest);
}

char *my_realloc(char *str, int size)
{
    char *new = malloc(my_strlen(str) + size);

    my_strncpy(new, str, my_strlen(str) + 1);
    free(str);
    return (new);
}