/*
** EPITECH PROJECT, 2019
** direction
** File description:
** control part for sokoban
*/

#include "../include/my.h"

int direction(soko_t *data, int c)
{
    switch (c) {
    case KEY_UP:
        up(data);
        break;
    case KEY_DOWN:
        down(data);
        break;
    case KEY_LEFT:
        left(data);
        break;
    case KEY_RIGHT:
        right(data);
        break;
    case 32:
        for (int i = 0; data->buf[i] != '\0'; i++)
            data->buf[i] = data->ori[i];
        break;
    default:
        return (0);
        break;
    }
}