/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_tower
*/

#include "defender.h"

void init_tower1(sfTexture *tex, sfSprite *spr, int x, int y)
{
    sfSprite_setTexture(spr, tex, sfTrue);
    sfSprite_setPosition(spr, (sfVector2f) {x, y});
}

void init_tower(game_object_t *g)
{
    g->tex_tower1 = sfTexture_createFromFile("cuties/tour1p.png", NULL);
    g->spri_tower1 = sfSprite_create();
    g->tex_tower2 = sfTexture_createFromFile("cuties/tour2p.png", NULL);
    g->spri_tower2 = sfSprite_create();
    g->tex_tower3 = sfTexture_createFromFile("cuties/tour3p.png", NULL);
    g->spri_tower3 = sfSprite_create();
    init_tower1(g->tex_tower1, g->spri_tower1, 0, 0);
    init_tower1(g->tex_tower2, g->spri_tower2, 0.8, 0.8);
    init_tower1(g->tex_tower3, g->spri_tower3, 0.4, 0.4);
}