/*
** EPITECH PROJECT, 2019
** change_map
** File description:
** change map after each move
*/

#include "../include/my.h"

char change_map(map_t *map)
{
    int last = 0;

    while (map->line > map->size || check_line(map) < map->num) {
        my_putstr("There haven't enough stick to take\n");
        play(map);
    }
    while (map->num > map->nbr) {
        my_putstr("Sorry, you cant take such much sticks\n");
        play(map);
    }
    for (int i = 0; i <= map->max; i++)
        if (map->match[map->line][i] == '|')
            last = i;
    for (int i = 0; i < map->num; i++,last--)
        map->match[map->line][last] = ' ';
    for (int i = 0; i < map->size + 2; i++)
            my_printf("%s\n",map->match[i]);
        my_printf("\n");
}
