/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** sort.c
*/

#include "tetris.h"

int my_sort_alpha(int *elems, char **src, int success)
{
    int size = num_tetrimi();
    char *tmp;
    int n_order = 0;

    for (int i = 0; i < size - 1; i++) {
        if (my_strcmp(src[i], src[i + 1]) > 0) {
            tmp = my_strdup(src[i]);
            src[i] = my_strdup(src[i + 1]);
            src[i + 1] = my_strdup(tmp);
            n_order = elems[i];
            elems[i] = elems[i + 1];
            elems[i + 1] = n_order;
            success = 0;
        }
    }
    return (success);
}

int *get_sorted_list(tetris_t *tetris)
{
    int *elems = malloc(sizeof(int) * tetris->num_tetri);
    char **tmp = malloc(sizeof(char *) * tetris->num_tetri);
    int success = 0;

    if (elems == NULL || tmp == NULL)
        return (NULL);
    for (int i = 0; i < tetris->num_tetri; i++) {
        tmp[i] = get_name(i);
        elems[i] = i;
    }
    while (success == 0) {
        success = 1;
        success = my_sort_alpha(elems, tmp, success);
    }
    free(tmp);
    return (elems);
}
