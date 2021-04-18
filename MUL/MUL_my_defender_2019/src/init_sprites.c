/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_sprites.c
*/

#include "defender.h"

void set_enemy_sprite(sfSprite *gol, sfTexture *tex)
{
    sfSprite_setTexture(gol, tex, sfTrue);
    sfSprite_scale(gol, (sfVector2f){1,1});
    sfSprite_setPosition(gol, (sfVector2f) {-50.0, 80.0});
}

void init_golem_walk(game_object_t *gol, UNUSED win_t *w)
{
    gol->clock = sfClock_create();
    gol->tex1 = sfTexture_createFromFile(ENEMY_ONE, NULL);
    gol->spr1 = sfSprite_create();
    set_enemy_sprite(gol->spr1, gol->tex1);
    // gol->tex2 = sfTexture_createFromFile(ENEMY_TWO, NULL);
    // gol->spr2 = sfSprite_create();
    // set_enemy_sprite(gol->spr2, gol->tex2);
}

void init_enemy(game_object_t *gol, win_t *w)
{
    gol->square.top = 0;
    gol->square.left = 0;
    gol->square.width = 180;
    gol->square.height = 120;
    init_golem_walk(gol, w);
}