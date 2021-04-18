/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** debug.c
*/

#include "tetris.h"

void debug(tetris_t *tetris)
{
    tetris->map->top_height = 0;
    tetris->map->top_width = 0;

    if (tetris->is_debug_on == true) {
        my_printf("*** DEBUG MODE ***\n");
        display_keys(tetris);
    }
    tetris->map->tetri = malloc(sizeof(char *) * tetris->num_tetri);
    display_tetriminos(tetris);
    if (tetris->is_debug_on == true)
        my_printf("Press any key to start Tetris\n");
}

void debug_reader(tetris_t *tetris, int i, int num)
{
    char *name_tetri = get_file_name(get_name(i));
    int return_tetrimino_value = get_tetriminos(tetris->map, i, num);

    if (tetris->is_debug_on == true) {
        my_printf("Tetriminos : Name %s : ", name_tetri);
        if (return_tetrimino_value == 0)
            my_printf("Error\n");
        else display_tetri(tetris->map);
    }
}

void display_tetri(map_t *map)
{
    my_printf("Size %i*%i", map->size_y, map->size_x);
    my_printf(" : Color %i : ", map->color);
    my_printf("%s", map->buf);
}
