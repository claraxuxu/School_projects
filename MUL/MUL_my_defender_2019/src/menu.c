/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** menu.c
*/

#include "defender.h"

void check_pos_menu(menu_t *m, sfVector2i vect, sfRenderWindow *w)
{
    if (vect.x >= 736 && vect.x <= 1009) {
        if (vect.y >= 353 && vect.y <= 416) m->g->scene = 3;
        if (vect.y >= 454 && vect.y <= 511) m->g->scene = 2;
        if (vect.y >= 549 && vect.y <= 612) {
            m->g->scene_before = 0;
            m->g->scene = 1;
        }
        if (vect.y >= 652 && vect.y <= 717) sfRenderWindow_close(w);
    }
}

void event_menu(menu_t *m, win_t *w)
{
    sfEvent event;
    sfWindow *actual = NULL;
    sfVector2i vect;

    if (sfRenderWindow_pollEvent(w->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w->win);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(w->win);
        if (event.type == sfEvtMouseButtonReleased) {
            vect = sfMouse_getPosition(actual);
            check_pos_menu(m, vect, w->win);
        }
    }
    sfWindow_destroy(actual);
}

void draw_text_menu(menu_t *m, win_t *w)
{
    sfRenderWindow_drawText(w->win, m->tplay, NULL);
    sfRenderWindow_drawText(w->win, m->thowto, NULL);
    sfRenderWindow_drawText(w->win, m->tsettings, NULL);
    sfRenderWindow_drawText(w->win, m->texit, NULL);
}

void menu(menu_t *m, win_t *w)
{
    sfRenderWindow_drawSprite(w->win, m->fontmenu, NULL);
    draw_text_menu(m, w);
    event_menu(m, w);
}