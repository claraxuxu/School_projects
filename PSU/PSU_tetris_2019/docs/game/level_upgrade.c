/*
** EPITECH PROJECT, 2020
** level_upgrade
** File description:
** function that handles level of the game.
*/

#include "tetris.h"

int this_line_is_full(list_t *map_calc, int col_max)
{
    int this_line = 0;
    line *current = map_calc->first;

    while (current != NULL) {
        if (count_that_char(current->cur_line, '*') == col_max)
            return this_line;
        this_line++;
        current = current->next;
    }
    return -1;
}

list_t *upgrade_map_by_removing_line(list_t *interface, tetris_t *data,
int line)
{
    char *new_empty_line = my_memset(data->map_width, ' ');

    delete_node_in_middle_list(interface, line);
    insertion(interface, new_empty_line);
    return interface;
}

void upgrade_level(tetris_t *data)
{
    if (data->score != 0 && data->score % 10 == 0) {
        data->level++;
        data->speed--;
    }
}
