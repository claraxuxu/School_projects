/*
** EPITECH PROJECT, 2019
** check_lb
** File description:
** check part
*/

#include "../include/my.h"

void check_b(la_t *list)
{
    if (list->lb[0] < list->lb[my_strlen(list->lb) - 1])
        rb(list);
    if (list->lb[0] < list->lb[1])
        sb(list);
    if (list->lb[my_strlen(list->lb) - 1] <= list->lb[0])
        rrb(list);
}