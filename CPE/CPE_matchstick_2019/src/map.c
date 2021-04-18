/*
** EPITECH PROJECT, 2019
** map
** File description:
** original map after user gave size
*/

#include "../include/my.h"

void make_square(map_t *map)
{
    for (int i = 0; i < map->size + 2; i++)
        map->match[i][0] = '*';
    for (int i = 1; i <= map->size; i++)
        map->match[i][map->max + 1] = '*';
    for (int i = 0; i < map->size + 2; i++)
        my_printf("%s\n",map->match[i]);
    my_putchar('\n');
}
char triangle(map_t *map)
{
    map->space = map->max / 2;
    for (int i = 1; i <= map->size; i++) {
        for (int j = 1; j <= map->space - i + 1; j++)
            map->match[i][j] = ' ';
        for (int k = map->space - i + 2; k < map->space + i + 1; k++)
            map->match[i][k] = '|';
        for (int s = map->space + i + 1; s <= map->max; s++)
            map->match[i][s] = ' ';
    }
    make_square(map);
}
char map(map_t *map)
{
    int j = 0;

    map->max = 2 * (map->size - 1) + 1;
    map->match = malloc(sizeof(char*) * map->size + 2);
    for (int i = 0; i < map->size + 3; i++)
        map->match[i] = malloc(sizeof(char) * map->max + 3);
    for (int j = 0; j < map->max + 2; j++) {
        map->match[0][j] = '*';
        map->match[map->size + 1][j] = '*';
    }
    map->match[0][j] = '\0';
    triangle(map);
    play(map);
}
