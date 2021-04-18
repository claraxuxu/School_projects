/*
** EPITECH PROJECT, 2019
** pa_pb
** File description:
** for pushswap
*/

#include "../include/my.h"

void pa(la_t *list)
{
    int *instead_a = malloc(sizeof(int*) * my_strlen(list->la));
    int *instead_b = malloc(sizeof(int*) * my_strlen(list->lb));

    for (int i = 1; i <= my_strlen(list->la); i++)
        instead_a[i] = list->la[i - 1];
    instead_a[0] = list->lb[0];
    list->la = instead_a;
    for (int i = 1; i < my_strlen(list->lb); i++)
        instead_b[i - 1] = list->lb[i];
    list->lb = instead_b;
    my_putstr("pa");
    if (check_la(list) == 0 && my_strlen(list->lb) == 0) {
        my_putchar('\n');
        exit (0);
    }
    my_putchar(' ');
}

void pb(la_t *list)
{
    int *instead_a = malloc(sizeof(int*) * my_strlen(list->la));
    int *instead_b = malloc(sizeof(int*) * my_strlen(list->lb));

    for (int i = 1; i <= my_strlen(list->lb); i++)
        instead_b[i] = list->lb[i - 1];
    instead_b[0] = list->la[0];
    list->lb = instead_b;
    for (int i = 1; i < my_strlen(list->la); i++)
        instead_a[i - 1] = list->la[i];
    list->la = instead_a;
    my_putstr("pb");
    if (check_la(list) == 0 && my_strlen(list->lb) == 0){
        my_putchar('\n');
        exit (0);
    }
    my_putchar(' ');
}
