/*
** EPITECH PROJECT, 2019
** ra_rb_rr
** File description:
** for pushswap
*/

#include "../include/my.h"

void ra(la_t *list)
{
    int *instead = malloc(sizeof(int*) * my_strlen(list->la));

    for (int i = 0; i < my_strlen(list->la) - 1; i++)
        instead[i] = list->la[i + 1];
    instead[my_strlen(list->la) - 1] = list->la[0];
    list->la = instead;
    my_putstr("ra");
    if (check_la(list) == 0 && my_strlen(list->lb) == 0){
        my_putchar('\n');
        exit (0);
    }
    my_putchar(' ');
}

void rb(la_t *list)
{
    int *instead = malloc(sizeof(int*) * my_strlen(list->lb));

    for (int i = 0; i < my_strlen(list->lb) - 1; i++)
        instead[i] = list->lb[i + 1];
    instead[my_strlen(list->lb) - 1] = list->lb[0];
    list->lb = instead;
    my_putstr("rb");
    if (check_la(list) == 0 && my_strlen(list->lb) == 0){
        my_putchar('\n');
        exit (0);
    }
    my_putchar(' ');
}

void rr (la_t *list)
{
    int *instead = malloc(sizeof(int*) * my_strlen(list->la));
    int *instead1 = malloc(sizeof(int*) * my_strlen(list->lb));

    for (int i = 0; i < my_strlen(list->la) - 1; i++)
        instead[i] = list->la[i + 1];
    instead[my_strlen(list->la) - 1] = list->la[0];
    list->la = instead;
    for (int i = 0; i < my_strlen(list->lb) - 1; i++)
        instead1[i] = list->lb[i + 1];
    instead1[my_strlen(list->lb) - 1] = list->lb[0];
    list->lb = instead1;
    my_putstr("rr");
    if (check_la(list) == 0 && my_strlen(list->lb) == 0){
        my_putchar('\n');
        exit (0);
    }
    my_putchar(' ');
}