/*
** EPITECH PROJECT, 2019
** len
** File description:
** get len of the key matrix
*/

#include "../include/my.h"

int len(char *av)
{
    int len = my_strlen(av);

    if (len <= 1)
        return (1);
    else if (len <= 4)
        return (4);
    else if (len <= 9)
        return (9);
    else if (len <= 16)
        return (16);
    else if (len > 16)
        exit (84);
}
