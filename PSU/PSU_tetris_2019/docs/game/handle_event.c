/*
** EPITECH PROJECT, 2020
** handle_event
** File description:
** functions that handles input and game upgrade events.
*/

#include "tetris.h"

void quit_the_game(tetris_t *data, display_t *disp)
{
    clock_t elapsed = clock();
    elapsed /= CLOCKS_PER_SEC;

    while (last_pause_display_condition(elapsed))
        display_map(disp, data);
    delwin(data->game.win);
    endwin();
    exit(0);
}

void put_pause(tetris_t *data)
{
    while (getch() != data->game.pause);
}

void moves_gestion(tetris_t *data, display_t *disp, int key)
{
    bool is_left = false;

    if (key == data->game.turn_it)
        if (you_can_turn_it(disp->tetrimino, data))
            disp->tetrimino = turn_it(disp->tetrimino);
    if (key == data->game.go_left)
        is_left = true;
    if (is_a_valid_move(disp->tetrimino, is_left))
        disp->tetrimino = is_left ? move_to_left(disp->tetrimino) :
            move_to_right(disp->tetrimino);
    else return;
}

void handle_input_events(tetris_t *data, display_t *disp, int key)
{
    if (key == data->game.quit)
        quit_the_game(data, disp);
    if (key == data->game.pause)
        put_pause(data);
    moves_gestion(data, disp, key);
    return;
}
