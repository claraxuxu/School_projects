/*
** EPITECH PROJECT, 2020
** u_dont_loose
** File description:
** function that check if the player is loosing.
*/

#include "tetris.h"
#include "map.h"

bool u_dont_loose(tetris_t *data, display_t *dis)
{
    if (count_that_lines(dis->tetrimino) + data->fill_lines
        > data->map_height)
        return false;
    return true;
}
