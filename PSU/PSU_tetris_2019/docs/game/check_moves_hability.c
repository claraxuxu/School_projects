/*
** EPITECH PROJECT, 2020
** check_move_hability
** File description:
** function that check that the tetri does not crosses the line.
*/

#include "tetris.h"

bool you_can_turn_it(char **tetri, tetris_t *data)
{
    int potential_cols = count_that_lines(tetri);

    if (potential_cols > data->map_width)
        return false;
    return true;
}

bool is_a_valid_move(char **tetri, bool is_left)
{
    int total_line = count_that_lines(tetri);
    int col = is_left == true ? 0 : my_strlen(tetri[0]) - 1;

    for (int line = 0; line < total_line; line++)
        if (tetri[line][col] == '*')
            return false;
    return true;
}

bool line_has_been_fill(list_t *map_calc, char **tetri, tetris_t *data)
{
    line *map_calc_line = map_calc->first;
    int tail_tetri = count_that_lines(tetri);

    if (data->map->tetri_head_line + tail_tetri == data->map_height) {
        data->map->tetri_head_line = 0;
        return true;
    }
    map_calc_line = points_to(map_calc_line, data->map->tetri_head_line + 1);
    for (int line_body_tetri = 0; map_calc_line != NULL
        && line_body_tetri < tail_tetri; line_body_tetri++) {
        for (int col = 0; col < data->map_width; col++) {
            if (tetri[line_body_tetri][col] == '*' &&
                map_calc_line->cur_line[col] == '*') {
                data->map->tetri_head_line = 0;
                return true;
            }
        }
        map_calc_line = map_calc_line->next;
    }
    return false;
}
