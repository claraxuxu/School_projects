/*
** EPITECH PROJECT, 2020
** display_interface
** File description:
** function that paths in the linked list interface and displays it.
*/

#include "tetris.h"

void display_map(display_t *disp, tetris_t *data)
{
    display_interface(disp->interface, data, disp);
    display_board(data, disp);
    if (data->able_preview == true)
        display_next_tetri(data, disp);
    wrefresh(data->game.win);
}

list_t *calc_map_and_tetri(display_t *disp, tetris_t *data)
{
    line *map_calc_line = disp->map_calc->first;
    line *inter_line = disp->interface->first;
    int t_line = 0;

    inter_line = points_to(inter_line, data->map->tetri_head_line);
    for (; disp->tetrimino[t_line] != NULL && inter_line != NULL; t_line++) {
        inter_line->cur_line = my_strdup(disp->tetrimino[t_line]);
        inter_line = inter_line->next;
    }
    map_calc_line = points_to(map_calc_line, t_line);
    while (map_calc_line != NULL && inter_line != NULL) {
        inter_line->cur_line = my_strdup(map_calc_line->cur_line);
        inter_line = inter_line->next;
        map_calc_line = map_calc_line->next;
    }
    return disp->interface;
}

void display_board(tetris_t *data, display_t *disp)
{
    int y = data->map->top_height + 8;
    int x = data->map_width + 8;
    clock_t time = clock();

    time /= CLOCKS_PER_SEC;
    mvwprintw(data->game.win, y, x, "Level : %d", data->level);
    mvwprintw(data->game.win, y + 1, x, "Score : %d", data->score);
    mvwprintw(data->game.win, y + 2, x, "High score : %d", data->level);
    mvwprintw(data->game.win, y + 3, x, "Lines : %d", data->fill_lines);
    mvwprintw(data->game.win, y + 5, x, "Time %d", time);
}

void display_interface(list_t *interface, tetris_t *tetris, display_t *disp)
{
    line *interface_line = interface->first;
    char *borders = my_memset(tetris->map_width, '-');
    int y = 0;

    interface = clean(interface);
    interface = calc_map_and_tetri(disp, tetris);
    mvwprintw(tetris->game.win, y, 5, "+%s+", borders);
    while (interface_line != NULL) {
        y++;
        mvwprintw(tetris->game.win, y, 5, "|%s|", interface_line->cur_line);
        interface_line = interface_line->next;
    }
    mvwprintw(tetris->game.win, y, 5, "+%s+\n", borders);
}
