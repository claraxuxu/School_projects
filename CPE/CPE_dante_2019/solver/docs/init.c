/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** init.c
*/

#include "../include/sol.h"

int init(sol_t *sol)
{
    sol->high = 0;
    for (int i = 0, len = 0; sol->buf[i] != '\0'; i++) {
        if (sol->buf[i] != '\n')
            len++;
        if (sol->buf[i] == '\n') {
            if (len != sol->width)
                return (-1);
            len = 0;
            sol->high++;
        }
    }
    sol->high++;
    sol->map = malloc(sizeof(int *) * sol->high);
    for (int i = 0; i < sol->high; i++)
        sol->map[i] = malloc(sizeof(int) * sol->width + 1);
    give_value(sol);
    return (0);
}