/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** give_value.c
*/

#include "../include/sol.h"

void give_value(sol_t *sol)
{
    for (int i = 0; sol->buf[i]; i++) {
        if (sol->buf[i] == '*')
            sol->buf[i] = '0';
        else if (sol->buf[i] == 'X')
            sol->buf[i] = '1';
    }
    for (int i = 0, a = 0, b = 0; sol->buf[i] != '\0'; i++, b++) {
        if (sol->buf[i] != '\n') {
            sol->map[a][b] = my_atoic(sol->buf[i]);
        }
        else if (sol->buf[i] == '\n') {
            b = -1;
            a++;
        }
    }
    judge_res(sol);
}
