/*
** EPITECH PROJECT, 2020
** get_biggest_tetri_dimensions
** File description:
** function that get the biggest tetri dimensions.
*/

#include "tetris.h"

int sort_by_biggest(int *array)
{
    int biggest = 0;

    for (int elem = 0; array[elem] != -1; elem++)
        if (array[elem] > biggest)
            biggest = array[elem];
    return biggest;
}

int *get_biggest_tetri_dimensions(map_t *map)
{
    int *biggest_width_height = malloc(sizeof(int) * 2);
    int *tetri_heights = NULL;
    int *tetri_widths = NULL;
    int nb_tetri = num_tetrimi();
    map->tetri = malloc(sizeof(char *) * (nb_tetri + 2));

    for (int i = 0; i < nb_tetri; i++) {
        if (!get_tetriminos(map, i, nb_tetri)) {
            intconcat(tetri_heights, map->size_y);
            intconcat(tetri_widths, map->size_x);
        }
        else exit(0);
    }
    biggest_width_height[0] = sort_by_biggest(tetri_widths);
    biggest_width_height[1] = sort_by_biggest(tetri_heights);
    free(tetri_heights);
    free(tetri_widths);
    return biggest_width_height;
}
