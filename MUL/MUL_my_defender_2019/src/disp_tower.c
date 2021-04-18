/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** disp_tower
*/

#include "defender.h"

void display_tower(char *tour, menu_t *m, win_t *w, game_object_t *g)
{
    if (m->g->tower > 0) {
        tour = my_strdup(my_itoa(m->g->tower));
        if (my_have(tour, '1') > 0) dis_tower1(w, g, my_have(tour, '1'));
        if (my_have(tour, '2') > 0) dis_tower2(w, g, my_have(tour, '2'));
        if (my_have(tour, '3') > 0) dis_tower3(w, g, my_have(tour, '3'));
    }
}

void dis_tower1(win_t *w, game_object_t *g, int tour)
{
    int x = 150;
    int y = 20;
    int y1 = 500;

    sfSprite_setPosition(g->spri_tower1, (sfVector2f) {x, y});
    sfRenderWindow_drawSprite(w->win, g->spri_tower1, NULL);
    if (tour >= 2) {
        sfSprite_setPosition(g->spri_tower1, (sfVector2f) {x, y1});
        sfRenderWindow_drawSprite(w->win, g->spri_tower1, NULL);
    }
}

void dis_tower2(win_t *w, game_object_t *g, int tour)
{
    int x = 150;
    int y = 280;
    int x1 = 980;
    int y1 = 500;
    
    sfSprite_setPosition(g->spri_tower2, (sfVector2f) {x, y});
    sfRenderWindow_drawSprite(w->win, g->spri_tower2, NULL);
    if (tour >= 2) {
        sfSprite_setPosition(g->spri_tower2, (sfVector2f) {x1, y1});
        sfRenderWindow_drawSprite(w->win, g->spri_tower2, NULL);
    }
}

void dis_tower3(win_t *w, game_object_t *g, int tour)
{
    int x = 580;
    int y = 530;
    int x1 = 1050;
    int y1 = 280;
    int x2 = 1350;
    int y2 = 350;
    
    sfSprite_setPosition(g->spri_tower3, (sfVector2f) {x, y});
    sfRenderWindow_drawSprite(w->win, g->spri_tower3, NULL);
    if (tour >= 2) {
        sfSprite_setPosition(g->spri_tower3, (sfVector2f) {x1, y1});
        sfRenderWindow_drawSprite(w->win, g->spri_tower3, NULL);
    }
    if (tour >= 3) {
        sfSprite_setPosition(g->spri_tower3, (sfVector2f) {x2, y2});
        sfRenderWindow_drawSprite(w->win, g->spri_tower3, NULL);
    }
}