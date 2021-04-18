/*
** EPITECH PROJECT, 2019
** check_num
** File description:
** check part of matchstick
*/

#include "../include/my.h"

void check_num(map_t *map)
{
    int i = 0;

    if (map->line > map->size) {
        i++;
        my_printf("Error: this line is out of range\n");
    }
    if (map->line <= 0) {
        my_printf("Error: invalid input (positive number expected)\n");
        i++;
    }
    if (i > 0)
        get_answer_user(map);
}
