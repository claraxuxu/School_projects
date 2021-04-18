/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** sol.h
*/

#ifndef _GENE_H_
#define _GENE_H_
#include <assert.h>
#include "../../outils/include/my.h"

#define WALL (1)
#define ROAD (0)
#define SOL (2)

typedef struct sol{
    char *buf;
    int **map;
    int **cp_map;
    int size;
    int width;
    int high;
    int begin;
    int end;
}sol_t;

int init(sol_t *sol);
int check(sol_t *sol, int ac, char **av);
void give_value(sol_t *sol);
void judge_res(sol_t *sol);
void find_way(int i, int j, sol_t *sol);
void try_up_down(int i, int j, sol_t *sol);
void try_left_right(int i, int j, sol_t *sol);
void check_road(int i, int j, sol_t *sol);
void print_solution(sol_t *sol);

#endif