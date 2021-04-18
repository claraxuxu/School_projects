/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** struct.h
*/

#include "defender.h"
#include "short_name.h"

typedef struct global_game
{
    int scene;
    int scene_before;
    int tower;
} global_t;

typedef struct win
{
    sfRenderWindow *win;
} win_t;

typedef struct set
{
    sfRectangleShape *back;
    sfRectangleShape *how_back;
} set_t;

typedef struct game
{
    sfRectangleShape *back_g;
    sfText *money;
    sfText *note;
    int castle;
    sfText *chateau;
} game_t;

typedef struct mouse
{
    sfVector2i click;
    sfVector2i pos;
    sfTexture *text_target;
    sfSprite *spr_target;
    sfVector2f pos_target;
}mouse_t;

typedef struct game_object
{
    int scene;
    sfTexture *tex1;
    sfSprite *spr1;
    sfTexture *tex2;
    sfSprite *spr2;
    sfTexture *tex3;
    sfSprite *spr3;
    sfClock *clock;
    sfTexture *tex_tower1;
    sfSprite *spri_tower1;
    sfTexture *tex_tower2;
    sfSprite *spri_tower2;
    sfTexture *tex_tower3;
    sfSprite *spri_tower3;
    sfIntRect square;
    mouse_t mouse;
} game_object_t;

typedef struct sprite
{
    sfTexture *texture1;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect cut;
    sfVector2f pos;
    sfVector2f speed;
    sfSprite *wall;
    int d;
    int y;
} sprite_t;

typedef struct menu
{
    set_t *set;
    game_t *game;
    global_t *g;
    sprite_t *s;
    sfMusic *mmusic;
    sfSprite *fontsettings;
    sfSprite *fontmenu;
    sfSprite *fontgame;
    sfSprite *fonthow;
    sfText *texit;
    sfText *tplay;
    sfText *tsettings;
    sfText *thowto;
} menu_t;