/*
** EPITECH PROJECT, 2019
** play
** File description:
** play part of matchstick
*/

#include "../include/my.h"

char display_sentence(map_t *map)
{
    my_printf("Player removed %i match(es) ",map->num);
    my_printf("from line %i\n",map->line);
}
char map_is_zero(map_t *map)
{
    my_printf("You lost, too bad...\n");
    map->exit = 2;
}
char play(map_t *map)
{
    char *str;

    map->line = 0;
    map->num = 0;
    srandom((unsigned)time(NULL));
    while (check(map) > 0 && map->exit != 0) {
        my_printf("Your turn:\n");
        get_answer_user(map);
        if (map->exit == 0)
            break;
        get_answer_match(map);
        if (map->exit == 0)
            break;
        display_sentence(map);
        change_map(map);
        if (check(map) == 0)
            map_is_zero(map);
        else
            play_bot(map);
    }
}
