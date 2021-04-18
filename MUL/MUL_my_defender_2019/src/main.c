/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "defender.h"

void how(menu_t *m, win_t *w)
{
    sfRenderWindow_drawSprite(w->win, m->fonthow, NULL);
    m->set->how_back = sfRectangleShape_create();
    sfRectangleShape_setPosition(m->set->how_back, (sfVector2f) {92, 90});
    sfRectangleShape_setSize(m->set->how_back, (sfVector2f) {100, 63});
    sfRectangleShape_setFillColor(m->set->how_back, sfTransparent);
    event_setting(m->set->how_back, m, w);
}

void scene_select(menu_t *m, win_t *w, game_object_t *g)
{
    char *tour = malloc(sizeof(char) * 8);

    if (m->g->scene == 0)
        menu(m, w);
    if (m->g->scene == 1)
        setting(m, w);
    if (m->g->scene == 2)
        how(m, w);
    if (m->g->scene == 3) {
        sfRenderWindow_drawSprite(w->win, m->fontgame, NULL);
        init_game(m, w, g);
        event_game(m, w, g);
        display_tower(tour, m, w, g);
        my_realloc(tour, 2);
    }
}

void game_loop(win_t *w, menu_t *m, game_object_t *gol1)
{
    m->g->scene = 0;
    while (sfRenderWindow_isOpen(w->win)) {
        sfRenderWindow_clear(w->win, sfBlack);
        scene_select(m, w, gol1);
        sfRenderWindow_display(w->win);
    }
    destroy(m, w);
}

int main(UNUSED int ac, UNUSED char **av)
{
    win_t *w = malloc(sizeof(win_t));
    menu_t *m = malloc(sizeof(menu_t));
    game_object_t *g = malloc(sizeof(game_object_t));
    init_struct(m);
    w->win = createwin(w->win);
    init_menu(m);
    init_enemy(g, w);
    init_tower(g);
    sfMusic_play(m->mmusic);
    game_loop(w, m, g);
    return (0);
}
