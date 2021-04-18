/*
** EPITECH PROJECT, 2019
** check
** File description:
** check part of matchstick
*/

#include "../include/my.h"

int check(map_t *map)
{
    int n = 0;

    for (int i = 0; i < map->size + 2; i++)
        for (int j = 0; j < map->max + 2; j++)
            if (map->match[i][j] == '|')
                n++;
    return (n);
}
int check_line(map_t *map)
{
    int n = 0;

    for (int i = 0; i <= map->max; i++)
        if (map->match[map->line][i] == '|')
            n++;
    return (n);
}
