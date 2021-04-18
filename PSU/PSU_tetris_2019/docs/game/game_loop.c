/*
** EPITECH PROJECT, 2020
** game_loop
** File description:
** function that handles the tetris game loop.
*/

#include "tetris.h"

bool last_pause_display_condition(clock_t elapsed)
{
    clock_t pause = clock();

    pause /= CLOCKS_PER_SEC;
    if (pause - elapsed >= 2)
        return true;
    return false;
}

void game_loop(tetris_t *data, display_t *display)
{
    display->tetrimino = get_tetri(data, display);
    clock_t time = clock() / CLOCKS_PER_SEC;
    clock_t elapsed;
    int key = 0;

    while (1) {
        display->next_tetrimino = get_tetri(data, display);
        while (line_has_been_fill(display->map_calc, display->tetrimino, data)
        == false) {
            key = getch();
            display_map(display, data);
            handle_game_events(data, display, time, elapsed);
            display_map(display, data);
            handle_input_events(data, display, key);
        }
        data->fill_lines++;
        display->map_calc = copy(display->interface, display->map_calc);
        display->tetrimino = display->next_tetrimino;
    }
    quit_the_game(data, display);
}
