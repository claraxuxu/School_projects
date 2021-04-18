/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** print_res.c
*/

#include "../include/sol.h"

void print_solution(sol_t *sol)
{
    for (int i = 0; i < sol->high - 1; i++) {
        for (int j = 0; j < sol->width; j++) {
            if (sol->cp_map[i][j] == 1) printf("X");
            else if (sol->cp_map[i][j] == 0 || sol->cp_map[i][j] == 3)
                printf("*");
            else if (sol->cp_map[i][j] == 2)
                printf("o");
        }
        printf("\n");
    }
    for (int j = 0; j < sol->width; j++) {
        if (sol->cp_map[sol->high - 1][j] == 1) printf("X");
        else if (sol->cp_map[sol->high - 1][j] == 0 ||
                sol->cp_map[sol->high - 1][j] == 3)
            printf("*");
        else if (sol->cp_map[sol->high - 1][j] == 2)
            printf("o");
    }
}
