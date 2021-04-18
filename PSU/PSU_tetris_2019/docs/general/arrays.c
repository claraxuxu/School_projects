/*
** EPITECH PROJECT, 2020
** arrays.c
** File description:
** array stuff.
*/

#include "tetris.h"

int *tabdup(int tab)
{
    int *dest = malloc(sizeof(int) * 2);

    dest[0] = tab;
    dest[1] = -1;
    return dest;
}

int intlen(int *tab)
{
    int i = 0;

    for (; tab[i] != -1; i++);
    return (i);
}

int *sub_intconcat(int *tab1, int tab2)
{
    int len = intlen(tab1);
    int *dest = malloc(sizeof(int) * (len + 2));
    int i = 0;

    for (; i < len; i++)
        dest[i] = tab1[i];
    dest[i] = tab2;
    dest[i + 1] = -1;
    return (dest);
}

int *intconcat(int *tab1, int tab2)
{
    if (tab1 == NULL)
        return (tabdup(tab2));
    return (sub_intconcat(tab1, tab2));
}

int array_cmp(int *tab)
{
    for (int elem = 0; tab[elem] != -1; elem++) {
        for (int i = elem + 1; tab[i] != -1; i++)
            if (tab[elem] == tab[i])
                return 1;
    }
    return 0;
}
