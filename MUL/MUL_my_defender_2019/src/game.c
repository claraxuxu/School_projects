/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game.c
*/

#include "defender.h"

int pos_mouse_game(sfVector2i click_pos, int x, int y)
{
    int max_x = x + 100;
    int max_y = y + 70;

    if (click_pos.x >= x && click_pos.x <= max_x)
        if (click_pos.y >= y && click_pos.y <= max_y)
            return (1);
    return (0);
}

void clicked(sfVector2i vect, menu_t *m, UNUSED win_t *w)
{
    if (pos_mouse_game(vect, 1775, 55) == 1) {
        m->g->scene_before = 3;
        m->g->scene = 1;
    }
    else if (pos_mouse_game(vect, 73, 974) == 1)
        m->g->scene = 0;
    if (vect.y >= 914 && vect.y <= 1036) {
        if (vect.x >= 344 && vect.x <= 472)
            m->g->tower = (m->g->tower * 10) + 1;
        if (vect.x >= 589 && vect.x <= 665)
            m->g->tower = (m->g->tower * 10) + 2;
        if (vect.x >= 819 && vect.x <= 970)
            m->g->tower = (m->g->tower * 10) + 3;
    }
}

void event_game(menu_t *m, win_t *w, UNUSED game_object_t *g)
{
    sfEvent event;
    sfWindow *actual = NULL;
    sfVector2i vect;

    if (sfRenderWindow_pollEvent(w->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w->win);
        if (event.type == sfEvtMouseButtonReleased) {
            vect = sfMouse_getPosition(actual);
            clicked(vect, m, w);
        }
    }
    sfWindow_destroy(actual);
}

void note_money(menu_t *m, win_t *w)
{
    static float money = 100;
    static float note = 0;

    money += 0.003;
    note += 0.005;
    m->game->note = create_font(m->game->note, my_itoa(note), 870, 490);
    sfRenderWindow_drawText(w->win, m->game->note, NULL);
    m->game->money = create_font(m->game->money, my_itoa(money), 1020, 15);
    sfRenderWindow_drawText(w->win, m->game->money, NULL);
    m->game->chateau = create_font(m->game->chateau, 
    my_itoa(m->game->castle), 1760, 235);
    sfText_setColor(m->game->chateau, sfRed);
    sfRenderWindow_drawText(w->win, m->game->chateau, NULL);
}

void init_game(menu_t *m, win_t *w, game_object_t *gol)
{
    note_money(m, w);
    move_golem_walk(m, gol, w);
}