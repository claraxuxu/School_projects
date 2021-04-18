/*
** EPITECH PROJECT, 2019
** rra_rrb_rrr
** File description:
** for pushswap
*/

#include "../include/my.h"

void rra(la_t *list)
{
    int *instead = malloc(sizeof(int*) * my_strlen(list->la));

    for (int i = 0; i < my_strlen(list->la) - 1; i++)
        instead[i + 1] = list->la[i];
    instead[0] = list->la[my_strlen(list->la) - 1];
    list->la = instead;
    my_putstr("rra");
    if (check_la(list) == 0 && my_strlen(list->lb) == 0){
        my_putchar('\n');
        exit (0);
    }
    my_putchar(' ');
}

void rrb(la_t *list)
{
    int *instead = malloc(sizeof(int*) * my_strlen(list->lb));

    for (int i = 0; i < my_strlen(list->lb) - 1; i++)
        instead[i + 1] = list->lb[i];
    instead[0] = list->lb[my_strlen(list->lb) - 1];
    list->lb = instead;
    my_putstr("rrb");
    if (check_la(list) == 0 && my_strlen(list->lb) == 0){
        my_putchar('\n');
        exit (0);
    }
    my_putchar(' ');
}

void rrr(la_t *list)
{
    int *instead = malloc(sizeof(int*) * my_strlen(list->la));
    int *instead1 = malloc(sizeof(int*) * my_strlen(list->lb));

    for (int i = 0; i < my_strlen(list->la) - 1; i++)
        instead[i + 1] = list->la[i];
    instead[0] = list->la[my_strlen(list->la) - 1];
    list->la = instead;
    for (int i = 0; i < my_strlen(list->lb) - 1; i++)
        instead1[i + 1] = list->lb[i];
    instead1[0] = list->lb[my_strlen(list->lb) - 1];
    list->lb = instead1;
    my_putstr("rrr");
    if (check_la(list) == 0 && my_strlen(list->lb) == 0){
        my_putchar('\n');
        exit (0);
    }
    my_putchar(' ');
}
