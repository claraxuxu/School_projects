/*
** EPITECH PROJECT, 2019
** my
** File description:
** my_itoa.c
*/

#include <stdlib.h>

char *itoa(int nb)
{
    char *res;
    int x = 0;

    for (int i = nb; i != 0; x++)
        i /= 10;
    res = malloc(sizeof(char) * x + 1);
    res[x] = '\0';
    x--;
    for (; x >= 0; x--) {
        res[x] = nb % 10 + 48;
        nb /= 10;
    }
    return (res);
}