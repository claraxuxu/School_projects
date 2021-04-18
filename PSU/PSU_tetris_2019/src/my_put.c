/*
** EPITECH PROJECT, 2019
** my_put
** File description:
** basic puts
*/

#include "tetris.h"

int my_put_nbr(int nb)
{
    int n;

    if (nb < 0)
        nb = -nb;
    n = nb % 10;
    if (nb != n)
        my_put_nbr((nb - n) / 10);
    my_putchar(n + 48);
    return (n);
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void my_putchar(char c)
{
    write(1, &c, 1);
}