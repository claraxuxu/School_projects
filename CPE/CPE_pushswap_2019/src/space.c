/*
** EPITECH PROJECT, 2019
** space
** File description:
** check space part
*/

#include "../include/my.h"

int space(la_t *list)
{
    if (check_la(list) == 0 && my_strlen(list->lb) == 0)
        return (0);
    my_putchar(' ');
}