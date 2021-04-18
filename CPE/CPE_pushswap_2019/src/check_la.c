/*
** EPITECH PROJECT, 2019
** check_la
** File description:
** check part
*/

#include "../include/my.h"

int check_la(la_t *list)
{
    int y = 0;

    for (int i = 1; i < my_strlen(list->la); i++)
        if (list->la[i] < list->la[i - 1])
            y++;
    if (y > 0)
        return (1);
    return (0);
}

void check_a(la_t *list)
{
    if (list->la[0] > list->la[1])
        sa(list);
    if (list->la[0] > list->la[my_strlen(list->la) - 1])
        ra(list);
    if (list->la[my_strlen(list->la) - 1] <= list->la[0])
        rra(list);
}