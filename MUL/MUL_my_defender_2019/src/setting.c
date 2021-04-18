/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** setting.c
*/

#include "defender.h"

void chose_vol(menu_t *m, sfVector2i vect,  win_t *w)
{
    int x = vect.x;
    int y = vect.y;

    if (x >= 370 && x <= 543) {
        if (y >= 438 && y <= 484) sfMusic_setVolume(m->mmusic, 0.01);
        if (y >= 531 && y <= 571) sfMusic_setVolume(m->mmusic, 30);
        if (y >= 621 && y <= 661) sfMusic_setVolume(m->mmusic, 60);
        if (y >= 706 && y <= 756) sfMusic_setVolume(m->mmusic, 80);
        if (y >= 795 && y <= 840) sfMusic_setVolume(m->mmusic, 100);
    }
    else if (y >= 945 && y <= 1024) {
        if (x >= 104 && x <= 305)
            sfRenderWindow_close(w->win);
        if (x >= 587 && x <= 820) m->g->scene = 0;
    }
}

void check_pos_set(sfRectangleShape *a, menu_t *m, sfVector2i vect,  win_t *w)
{
    if (button_is_clicked(a, vect) == 1)
        m->g->scene = m->g->scene_before;
    else chose_vol(m, vect, w);
}

void event_setting( sfRectangleShape *a, menu_t *m, win_t *w)
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
            check_pos_set(a, m, vect, w);
        }
    }
    sfWindow_destroy(actual);
}

void init_set(menu_t *m)
{
    m->set->back = sfRectangleShape_create();
    sfRectangleShape_setPosition(m->set->back, (sfVector2f) {85, 94});
    sfRectangleShape_setSize(m->set->back, (sfVector2f) {153, 141});
    sfRectangleShape_setFillColor(m->set->back, sfTransparent);
}

void setting(menu_t *m, win_t *w)
{
    sfRenderWindow_drawSprite(w->win, m->fontsettings, NULL);
    init_set(m);
    event_setting(m->set->back, m, w);
}