/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** make list in right order
*/

#include "include/my.h"

void clean(la_t *list)
{
    if (my_strlen(list->lb) != 0) {
        if (list->lb[0] <= list->lb[my_strlen(list->lb) - 1])
            rb(list);
        if (list->lb[0] < list->lb[1] && list->la[0] > list->la[1])
            sc(list);
        else if (list->lb[0] < list->lb[1])
            sb(list);
    }
}

void fix(la_t *list)
{
    while (1) {
        if (list->la[0] >= list->la[my_strlen(list->la) - 1])
            ra(list);
        if (list->la[0] > list->la[1])
            sa(list);
        if (check_la(list) == 1 && (list->la[0] <= list->la[1])) {
            pb(list);
            clean(list);
        }
        while (check_la(list) == 0) {
            if (check_la(list) == 0 && my_strlen(list->lb) == 0)
                break;
            pa(list);
        }
        if (check_la(list) == 0 && my_strlen(list->lb) == 0)
            break;
    }
}

void pushswap(int ac, char **av)
{
    la_t list;
    list.la = malloc(sizeof(int*) * ac);
    list.lb = malloc(sizeof(int*) * ac);

    for (int i = 1; i < ac; i++)
        list.la[i - 1] = atoi(av[i]);
    if (check_la(&list) == 0) 
        my_putchar('\n');
    fix(&list);
    my_putchar('\n');
}

int main(int ac, char **av)
{
    if (ac >= 2&& isnum(ac,av) == 1)
        pushswap(ac,av);
    else
        exit (84);
}
