/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** judge_res.c
*/

#include "../include/sol.h"

void prepare(sol_t *sol)
{
    for (int i = 0; i < sol->high; i++) {
        for (int j = 0; j < sol->width; j++) {
            if (sol->map[i][j] == 1)
                sol->cp_map[i][j] = 1;
            else
                sol->cp_map[i][j] = 0;
        }
    }
}

void find_way(int i, int j, sol_t *sol)
{
    if (i == sol->high - 1 && j == sol->width - 1) {
        sol->cp_map[i][j] = 2;
        print_solution(sol);
        exit(0);
    } else {
        try_left_right(i, j, sol);
        try_up_down(i, j, sol);
    }
}

void judge_res(sol_t *sol)
{
    sol->cp_map = malloc(sizeof(int *) * sol->high);
    for (int i = 0; i < sol->high; i++)
        sol->cp_map[i] = malloc(sizeof(int) * (sol->width + 1));
    prepare(sol);
    if (sol->cp_map[1][1] == 1 && sol->cp_map[0][1] == 1) {
        printf("no way\n");
        exit (0);
    }
    find_way(0, 0, sol);
}
