/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** destroy.c
*/

#include "defender.h"

void destroy(menu_t *m, win_t *w)
{
    sfRenderWindow_destroy(w->win);
    free(w);
    sfMusic_destroy(m->mmusic);
    free(m);
}