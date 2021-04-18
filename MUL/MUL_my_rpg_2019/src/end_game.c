/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** end_game.c
*/

#include "rpg.h"

void check_tele(win_t *w, global_t *g)
{
    if (g->tele == 1)
        check_mouse(w, g);
    check_shop(w, g);
}

void button(win_t *w, global_t *g, sfVector2i vect)
{
    if (button_is_clicked(g->boss->leave, vect) == 1)
        sfRenderWindow_close(w->win);
}

void event(win_t *w, global_t *g)
{
    sfEvent event;
    sfVector2i vect = sfMouse_getPositionRenderWindow(w->win);

    if (sfRenderWindow_pollEvent(w->win, &event)) {
        if (event.type == sfEvtMouseButtonReleased) {
            button(w, g, vect);
        }
    }
}

void win_end(win_t *w, global_t *g)
{
    event(w, g);
    sfRenderWindow_drawRectangleShape(w->win, g->boss->leave, NULL);
}

void lose_end(win_t *w, global_t *g)
{
    event(w, g);
    sfRenderWindow_drawRectangleShape(w->win, g->boss->leave, NULL);
}