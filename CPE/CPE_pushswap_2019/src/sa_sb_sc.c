/*
** EPITECH PROJECT, 2019
** sa_sb_sc
** File description:
** change a_b list
*/

#include "../include/my.h"

void sa(la_t *list)
{
    int c = list->la[0];

    list->la[0] = list->la[1];
    list->la[1] = c;
    my_putstr("sa");
    if (check_la(list) == 0 && my_strlen(list->lb) == 0){
        my_putchar('\n');
        exit (0);
    }
    my_putchar(' ');
}

void sb(la_t *list)
{
    int c = list->lb[0];

    list->lb[0] = list->lb[1];
    list->lb[1] = c;
    my_putstr("sb");
    if (check_la(list) == 0 && my_strlen(list->lb) == 0){
        my_putchar('\n');
        exit (0);
    }
    my_putchar(' ');
}

void sc(la_t *list)
{
    int c = list->la[0];
    int b = list->lb[0];

    list->la[0] = list->la[1];
    list->la[1] = c;
    list->lb[0] = list->lb[1];
    list->lb[1] = b;
    my_putstr("sc");
    if (check_la(list) == 0 && my_strlen(list->lb) == 0){
        my_putchar('\n');
        exit (0);
    }
    my_putchar(' ');
}
