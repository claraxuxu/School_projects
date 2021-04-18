/*
** EPITECH PROJECT, 2020
** extract_size
** File description:
** functions that extract the size separated by a coma.
*/

#include "tetris.h"

void extract_size(tetris_t *tetris)
{
    static int fst_call = 0;

    if (fst_call == 0)
        tetris->map_width = my_getnbr(optarg);
    else tetris->map_height = my_getnbr(optarg);
    fst_call++;
}
