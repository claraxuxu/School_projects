/*
** EPITECH PROJECT, 2019
** get_binary
** File description:
** my_printf %b
*/

#include "../include/my.h"
#include "../include/printf.h"

void get_binary(int num)
{
    if (num == 0) {
        my_putchar('0');
        return;
    } else
        res_dif_int(num,2);
}


void get_float(double f)
{
    int temp = (int)f;

    res_dif_int(temp,10);
    my_putchar('.');
    f -= temp;
    if (f == 0) {
        for (temp = 0; temp < 6; temp++) {
            my_putchar('0');
        }
        return;
    } else {
        temp = (int)(f * 1000000);
        res_dif_int(temp,10);
    }
}

void get_octal(int num)
{
    if (num == 0) {
        my_putchar('0');
        return;
    } else
        res_dif_int(num,8);
}

