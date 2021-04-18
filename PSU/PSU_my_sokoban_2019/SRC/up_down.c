/*
** EPITECH PROJECT, 2019
** up_down
** File description:
** direction part for sokoban
*/

#include "../include/my.h"

int left(soko_t *data)
{
    if (data->buf[data->xp - 1] != '#' && data->buf[data->xp - 1] == 'X'
        && data->buf[data->xp - 2] != '#' && data->buf[data->xp - 2] != 'X') {
        data->buf[data->xp] = ' ';
        data->buf[data->xp - 1] = 'P';
        data->buf[data->xp - 2] = 'X';
        data->xp = data->xp - 1;
    }
    else if (data->buf[data->xp - 1] != '#' && (data->buf[data->xp - 1] == ' '
                                                || data->buf[data->xp - 1]
                                                == 'O') &&
             data->buf[data->xp - 1] != 'X') {
        data->buf[data->xp] = ' ';
        data->buf[data->xp - 1] = 'P';
        data->xp = data->xp - 1;
    }
}
int right(soko_t *data)
{
    if (data->buf[data->xp + 1] != '#' && data->buf[data->xp + 1] == 'X'
        && data->buf[data->xp + 2] != '#' && data->buf[data->xp + 2]!= 'X') {
        data->buf[data->xp] = ' ';
        data->buf[data->xp + 1] = 'P';
        data->buf[data->xp + 2] = 'X';
        data->xp = data->xp + 1;
    }
    else if (data->buf[data->xp + 1] != '#' && (data->buf[data->xp + 1] == ' '
                                                || data->buf[data->xp + 1]
                                                == 'O')) {
        data->buf[data->xp] = ' ';
        data->buf[data->xp + 1] = 'P';
        data->xp = data->xp + 1;
    }
}
int up(soko_t *data)
{
    if (data->buf[data->xp - data->len_line - 1] == 'X'
        && (data->buf[data->xp - (2 * (data->len_line + 1))] != '#'
            && data->buf[data->xp - (2 * (data->len_line + 1))] != 'X')) {
        data->buf[data->xp] = ' ';
        data->buf[data->xp - data->len_line - 1] = 'P';
        data->buf[data->xp - (2 * (data->len_line + 1))] = 'X';
        data->xp = data->xp - data->len_line - 1;
    }
    else if (data->buf[data->xp - data->len_line - 1] != '#' &&
             data->buf[data->xp - data->len_line - 1] != 'X') {
        data->buf[data->xp] = ' ';
        data->buf[data->xp - data->len_line - 1] = 'P';
        data->xp = data->xp - data->len_line - 1;
    }
}
int down(soko_t *data)
{
    if (data->buf[data->xp + data->len_line + 1] == 'X'
        && data->buf[data->xp + (2 * (data->len_line + 1))] != '#' &&
        data->buf[data->xp + (2 * (data->len_line + 1))] != 'X') {
        data->buf[data->xp] = ' ';
        data->buf[data->xp + data->len_line + 1] = 'P';
        data->buf[data->xp + (2 * (data->len_line + 1))] = 'X';
        data->xp = data->xp + data->len_line + 1;
    }
    else if (data->buf[data->xp + data->len_line + 1] != '#' &&
             data->buf[data->xp + data->len_line + 1] != 'X') {
        data->buf[data->xp] = ' ';
        data->buf[data->xp + data->len_line + 1] = 'P';
        data->xp = data->xp + data->len_line + 1;
    }
}
