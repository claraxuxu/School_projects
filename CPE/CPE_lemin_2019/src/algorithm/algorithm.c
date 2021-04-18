/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** algorithm.c
*/

#include "lemin.h"

void calcul_dis(info_t *info)
{
    if (info->j == info->j1)
        info->dis = info->k1 - info->k;
    else if (info->k1 == info->k)
        info->dis = info->j1 - info->j;
    else {
        info->dis = my_pow(info->k1 - info->k, 2);
        info->dis += my_pow(info->j1 - info->j, 2);
        info->dis = my_pow(info->dis, 0.5);
    }
}

void check_distance(info_t *info, int x, int y)
{
    if (x == my_atoi(info->start[0])) {
        info->j = my_atoi(info->start[2]);
        info->k = my_atoi(info->start[4]);
    } if (y == my_atoi(info->end[0])) {
        info->j1 = my_atoi(info->end[2]);
        info->k1 = my_atoi(info->end[4]);
    }
    for (int i = 0; info->room[i] != NULL; i++) {
        if (x == my_atoi(info->room[i][0])) {
            info->j = my_atoi(info->room[i][2]);
            info->k = my_atoi(info->room[i][4]);
        }
        if (y == my_atoi(info->room[i][0])) {
            info->j1 = my_atoi(info->room[i][2]);
            info->k1 = my_atoi(info->room[i][4]);
        }
    }
    calcul_dis(info);
}

void init_graph(info_t *info)
{
    int x = 0;
    int y = 0;

    info->dis = 0;
    for (int i = 0; info->pipe[i] != NULL; i++) {
        x = my_atoi(info->pipe[0][0]);
        y = my_atoi(info->pipe[0][2]);
        info->graph[x][y] = 0;
        check_distance(info, x, y);
        if (info->dis < 0) info->dis *= -1;
        info->graph[x][y] = info->dis;
    }
    
}
void get_max(info_t *info)
{
    info->n = 0;
    info->m = 0;

    if (my_atoi(info->start[0]) <= info->n) info->n = my_atoi(info->start[0]);
    if (my_atoi(info->end[0]) <= info->n) info->n = my_atoi(info->end[0]);
    if (my_atoi(info->start[0]) > info->m) info->m = my_atoi(info->start[0]);
    if (my_atoi(info->end[0]) > info->m) info->m = my_atoi(info->end[0]);
    for (int i = 0; info->room[i] != NULL; i++) {
        if (my_atoi(info->room[i][0]) <= info->n)
            info->n = my_atoi(info->room[i][0]);
        if (my_atoi(info->room[i][0]) > info->m) {
            info->m = my_atoi(info->room[i][0]);
        }
    }
    for(int i = 0; i <= info->n; ++i) {
        for(int j = 0; j <= info->m; ++j) {
            info->graph[i][j] = INF;
        }
    }
}
void algo(info_t *info)
{
    init_distance(info);
    get_max(info);
    init_graph(info);
    for (int i = 0; i <= info->n; ++i){
		for (int j = 0; j <= info->n; ++j){
			if (info->graph[i][j] == INF)
				info->graph[i][j] = info->graph[j][i];
		}
	}
}