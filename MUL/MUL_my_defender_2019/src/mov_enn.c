/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** mov_glo
*/

#include "defender.h"

void move_golem_walk(menu_t *m, game_object_t *g, win_t *w)
{
    sfTime time = sfClock_getElapsedTime(g->clock);
    float times = time.microseconds / 100000.0;

    sfSprite_setTextureRect(g->spr1, g->square);
    sfRenderWindow_drawSprite(w->win, g->spr1, NULL);
    if (times > 0.1) {
        g->square.left = g->square.left + 180;
        cas_mov(m, g);
        if (g->square.left == 3240)
            g->square.left = 0;
        sfClock_restart(g->clock);
    }
}

void cas_mov(menu_t *m, game_object_t *g)
{
    sfVector2f pos = sfSprite_getPosition(g->spr1);
    if (pos.x >= -50 && pos.x <= 40) move_right(g);
    if (pos.x == 42 && pos.y >= 80 && pos.y <= 652) move_down(g);
    if (pos.y == 654 && pos.x >= 42 && pos.x <= 1073) move_right(g);
    if (pos.x == 1074 && pos.y >= 418 && pos.y <= 654) move_up(g);
    if (pos.y == 416 && pos.x >= 1074 && pos.x <= 1200) move_right(g);
    if (pos.x == 1202 && pos.y >= 300 && pos.y <= 416) move_up(g);
    if (pos.y == 298 && pos.x >= 1202 && pos.x <= 1475) move_right(g);
    if (pos.y == 298 && pos.x > 1475) m->game->castle -= 0.5;
}

void move_right(game_object_t *g)
{
    sfSprite_move(g->spr1, (sfVector2f) {2, 0});
}

void move_down(game_object_t *g)
{
    sfSprite_move(g->spr1, (sfVector2f) {0, 2});
}

void move_up(game_object_t *g)
{
    sfSprite_move(g->spr1, (sfVector2f) {0, -2});
}