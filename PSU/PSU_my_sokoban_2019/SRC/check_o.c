/*
** EPITECH PROJECT, 2019
** check_o
** File description:
** check part for sokoban
*/

#include "../include/my.h"

void check_o(soko_t *data)
{
    for (int i = 0; i <= data->len_o; i++)
        if (data->buf[data->xo[i]] == ' ')
            data->buf[data->xo[i]] = 'O';
}