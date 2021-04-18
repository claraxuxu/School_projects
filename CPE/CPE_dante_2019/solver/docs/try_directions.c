/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** try_directions.c
*/

#include "../include/sol.h"

void check_road(int i, int j, sol_t *sol)
{
    if ((j - 1 >= 0 && sol->cp_map[i][j - 1] != 0 && sol->cp_map[i][j - 1]
        != 2) || (j + 1 < sol->width && sol->cp_map[i][j + 1] != 0 &&
        sol->cp_map[i][j + 1] != 2) ||
        (i - 1 >= 0 && sol->cp_map[i - 1][j] != 0 &&
        sol->cp_map[i - 1][j] != 2) ||
        (i + 1 < sol->high && sol->cp_map[i + 1][j] != 0 &&
        sol->cp_map[i + 1][j] != 2)) {
        printf("no way\n");
        exit (0);
    }
}

void try_left_right(int i, int j, sol_t *sol)
{
    if (j + 1 < sol->width && sol->cp_map[i][j + 1] == 0) {
        sol->cp_map[i][j] = 2;
        j++;
        find_way(i, j, sol);
        sol->cp_map[i][j] = 3;
        j--;
        sol->cp_map[i][j] = 0;
        check_road(i, j, sol);
    }
    if (i + 1 < sol->high && sol->cp_map[i + 1][j] == 0) {
        sol->cp_map[i][j] = 2;
        i++;
        find_way(i, j, sol);
        sol->cp_map[i][j] = 3;
        i--;
        sol->cp_map[i][j] = 0;
        check_road(i, j, sol);
    }
}

void try_up_down(int i, int j, sol_t *sol)
{
    if (i - 1 >= 0 && sol->cp_map[i - 1][j] == 0) {
        sol->cp_map[i][j] = 2;
        i--;
        find_way(i, j, sol);
        sol->cp_map[i][j] = 3;
        i++;
        sol->cp_map[i][j] = 0;
        check_road(i, j, sol);
    }
    if (j - 1 >= 0 && sol->cp_map[i][j - 1] == 0) {
        sol->cp_map[i][j] = 2;
        j--;
        find_way(i, j, sol);
        sol->cp_map[i][j] = 3;
        j++;
        sol->cp_map[i][j] = 0;
        check_road(i, j, sol);
    }
}
