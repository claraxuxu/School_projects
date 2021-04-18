/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init.c
*/

#include "defender.h"

void make_font(menu_t *m)
{
    m->tplay = create_font(m->tplay, "PLAY", 750, 300);
    m->thowto = create_font(m->thowto, "HOW TO PLAY", 750, 400);
    m->tsettings = create_font(m->tsettings, "SETTINGS", 750, 500);
    m->texit = create_font(m->texit, "EXIT", 750, 600);
}

void pos_sca(sfSprite *sprite, float a, float b, char *path)
{
    sfSprite_setTexture(sprite,
                        sfTexture_createFromFile(path, NULL), sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f) {0, 0});
    sfSprite_setScale(sprite, (sfVector2f) {a, b});
}

void init_menu(menu_t *m)
{
    m->mmusic = sfMusic_createFromFile("cuties/defender.ogg");
    sfMusic_setLoop(m->mmusic, sfTrue);
    sfMusic_setVolume(m->mmusic, 50);
    make_font(m);
    m->fontsettings = sfSprite_create();
    m->fontmenu = sfSprite_create();
    m->fontgame = sfSprite_create();
    m->fonthow = sfSprite_create();
    pos_sca(m->fontmenu, 1.84, 2.00, BEGIN);
    pos_sca(m->fonthow, 2.17, 1.92, HOW_PG);
    pos_sca(m->fontsettings, 1.9, 1.8, SET_PG);
    pos_sca(m->fontgame, 1, 0.95, GAME_PG);
}