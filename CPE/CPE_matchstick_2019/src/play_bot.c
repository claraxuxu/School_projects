/*
** EPITECH PROJECT, 2019
** play_bot
** File description:
** AI part of matchstick
*/

#include "../include/my.h"

char play_bot(map_t *map)
{
    int last = 0;
    int max_line = 0;

    map->line = crand(1, map->size);
    while (check_line(map) == 0)
        map->line = crand(1, map->size);
    max_line = check_line(map);
    if (max_line > map->nbr)
        max_line = map->nbr;
    map->num = crand(1, max_line);
    my_printf("AI's turn...\nAI removed %i match(es) ",map->num);
    my_printf("from line %i\n",map->line);
    change_map(map);
    if (check(map) == 0) {
        my_printf("I lost...snif...but I'll get you next time!!\n");
        map->exit = 1;
    }
}
