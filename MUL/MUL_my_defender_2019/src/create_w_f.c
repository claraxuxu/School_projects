/*
** EPITECH PROJECT, 2019
** MUL_my_defender_bootstrap_2019
** File description:
** createwin.c
*/

#include "defender.h"

sfRenderWindow *createwin(sfRenderWindow *w)
{
    sfVideoMode params = {1920, 1088, 32};

    w = sfRenderWindow_create(params, "My_defender", sfResize | sfClose, NULL);
    return (w);
}

sfText *create_font(sfText *text, char *str, int x, int y)
{
    text = sfText_create();
    sfText_setString(text, str);
    sfText_setPosition(text, (sfVector2f) {x, y});
    sfText_setFont(text, sfFont_createFromFile("cuties/font2.otf"));
    sfText_setCharacterSize(text, 50);
    return (text);
}