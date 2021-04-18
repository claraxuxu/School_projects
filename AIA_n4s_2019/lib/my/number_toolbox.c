/*
** EPITECH PROJECT, 2019
** number_toolbox.c
** File description:
** everything i may need to display a number
*/

#include "lib.h"

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 0) {
        if (nb >= 10) {
            my_putnbr(nb / 10);
            my_putchar(nb % 10 + 48);
        }
        else my_putchar(nb + 48);
    }
}

void my_putnbr_base(int nb, const char *base)
{
    char *converted_nb = my_getnbr_base(nb, base);

    if (converted_nb != (void *)0)
        my_putstr(converted_nb);
    test_if_free(converted_nb);
}

void my_putfloat(float nb)
{
    my_putnbr((int)nb);
    my_putchar('.');
    nb = nb - (int)nb;
    for (int i = 0; i < 6; i++) {
        if ((int)nb % 10 != 0 && ((int)nb * 10) % 10 != 0)
            break;
        nb = nb * 10;
        my_putchar((int)nb % 10 + 48);
    }
}