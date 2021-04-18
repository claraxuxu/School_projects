/*
** EPITECH PROJECT, 2020
** tetrimino_moves
** File description:
** functions that handles the movement of a tetrimino in a map.
*/

#include "tetris.h"
#include "map.h"

char **move_to_right(char **tetri)
{
    int total_line = count_that_lines(tetri);
    int total_col = my_strlen(tetri[0]);
    char **dest = malloc(sizeof(char *) * (total_line + 1));
    int col = 1;
    int line = 0;

    for (; line < total_line; line++) {
        dest[line] = malloc(sizeof(char) * (total_col + 1));
        dest[line][0] = ' ';
        for (col = 1; col < total_col; col++)
            dest[line][col] = tetri[line][col - 1];
        dest[line][col] = 0;
    }
    dest[line] = NULL;
    free_tab(tetri);
    return dest;
}

char **move_to_left(char **tetri)
{
    int total_line = count_that_lines(tetri);
    int total_col = my_strlen(tetri[0]);
    int col = 0;
    char **dest = malloc(sizeof(char *) * (total_line + 1));
    int line = 0;

    for (; line < total_line; line++) {
        dest[line] = malloc(sizeof(char) * (total_col + 1));
        for (col = 0; col < total_col - 1; col++)
            dest[line][col] = tetri[line][col + 1];
        dest[line][col] = ' ';
        dest[line][col + 1] = 0;
    }
    dest[line] = NULL;
    free_tab(tetri);
    return dest;
}

char **turn_it(char **tetri)
{
    char **dest = malloc(sizeof(char *) * (my_strlen(tetri[0]) + 1));
    int cur_line = 0;
    int cur_col = 0;
    int total_lines = my_strlen(tetri[0]);
    int total_cols = count_that_lines(tetri);

    for (int t_cols = total_lines - 1;
        cur_line < total_lines; cur_line++, total_cols--) {
        for (int t_line = total_cols - 1, cur_col = 0;
            cur_col < total_cols; total_cols++, t_line--)
            dest[cur_line][cur_col] = tetri[t_line][t_cols];
    }
    dest[cur_line] = NULL;
    free(tetri);
    return dest;
}

line *head_map_calc_line(line *map_calc_line)
{
    while (!find_char(map_calc_line->cur_line, '*'))
        map_calc_line = map_calc_line->next;
    return map_calc_line;
}

list_t *fall_a_bit(list_t *interface, list_t *map_calc,
char **tetri, tetris_t *tetris)
{
    interface = clean(interface);
    int len_tetri = count_that_lines(tetri);
    line *interface_line = interface->first;
    line *map_calc_line = map_calc->first;

    tetris->map->tetri_head_line++;
    for (int i = 0; i < tetris->map->tetri_head_line; i++)
        interface_line = interface_line->next;
    for (int i = 0; i < len_tetri; i++) {
        interface_line->cur_line = my_strdup(tetri[i]);
        interface_line = interface_line->next;
    }
    map_calc_line = head_map_calc_line(map_calc_line);
    while (map_calc_line != NULL) {
        interface_line->cur_line = my_strdup(map_calc_line->cur_line);
        interface_line = interface_line->next;
        map_calc_line = map_calc_line->next;
    }
    return interface;
}
