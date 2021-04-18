/*
** EPITECH PROJECT, 2020
** handle_game_event
** File description:
** function that handles speeds, etc
*/

#include "tetris.h"
#include "map.h"

void check_if_fall_naturally(clock_t elapsed, clock_t time, tetris_t *data,
display_t *disp)
{
    clock_t current_time = clock();

    current_time /= CLOCKS_PER_SEC;
    elapsed = time - current_time;
    if (elapsed > 0 && data->speed % elapsed == 0) {
        disp->interface = fall_a_bit(disp->interface,
        disp->map_calc, disp->tetrimino, data);
        data->map->tetri_head_line++;
    }
}

void display_next_tetri(tetris_t *data, display_t *disp)
{
    char *borders = my_memset(data->map_width, '-');
    int lines = 0;

    mvwprintw(data->game.win, lines, data->map_width + 6, "%s+",  borders);
    for (; disp->next_tetrimino[lines] != NULL; lines++)
        mvwprintw(data->game.win, lines + 1, data->map_width + 6, "|%s|",
        disp->next_tetrimino[lines]);
    mvwprintw(data->game.win, lines + 1, data->map_width + 6, "+%s+", borders);
}

void handle_game_events(tetris_t *data, display_t *disp, clock_t time,
clock_t elapsed)
{
    upgrade_level(data);
    check_if_fall_naturally(elapsed, time, data, disp);
    if (u_dont_loose == false)
        quit_the_game(data, disp);
}