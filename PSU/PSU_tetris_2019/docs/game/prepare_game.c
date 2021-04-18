/*
** EPITECH PROJECT, 2020
** prepare game
** File description:
** function that prepares game structures and game interface.
*/

#include "tetris.h"
#include "map.h"

list_t *init_interface(tetris_t *tetris)
{
    list_t *interface = initialisation(tetris);

    return clear_interface(interface, tetris);
}

void prepare_game(tetris_t *tetris)
{
    display_t display;
    display.interface = init_interface(tetris);
    display.map_calc = init_interface(tetris);

    tetris->speed = tetris->level + 2;
    game_loop(tetris, &display);
}
