/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** for bsq
*/

#include "my.h"

void my_putstr(char const *str)
{
    write(1,str,my_strlen(str));
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    int n;
    int var = 0;

    if (nb < 0) {
        my_putchar('-');
        if (nb == - 2147483648) {
            nb = 214748364;
            var = 8;
        }
        else
            nb = -nb;
    }
    n = nb % 10;
    if (nb != n)
        my_put_nbr((nb - n) / 10);
    my_putchar(n + 48);
    if (var)
        my_putchar(var + 48);
    return (n);
}