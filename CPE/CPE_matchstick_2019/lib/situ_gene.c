/*
** EPITECH PROJECT, 2019
** situ_gene
** File description:
** my_printf normal situations
*/

#include "../include/my.h"

void situ_gene(char *begin, va_list arg)
{
    switch (*begin) {
    case 'c':
        my_putchar(va_arg(arg, int));
        break;
    case 'd': case 'i':
        my_put_nbr(va_arg(arg, int));
        break;
    case 's':
        my_putstr(va_arg(arg, char*));
        break;
    case 'f':
        get_float(va_arg(arg, double));
        break;
    default:
        break;
    }
}
