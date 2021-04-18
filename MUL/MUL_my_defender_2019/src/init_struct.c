/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_struct.c
*/

#include "defender.h"

void init_struct(menu_t *m)
{
    m->g = malloc(sizeof(global_t));
    m->set = malloc(sizeof(set_t));
    m->game = malloc(sizeof(game_t));
    m->g->scene = 0;
    m->g->tower = 0;
    m->game->castle = 100;
}