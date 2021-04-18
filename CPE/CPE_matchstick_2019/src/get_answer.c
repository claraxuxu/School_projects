/*
** EPITECH PROJECT, 2019
** get_answer
** File description:
** get_answer part of matchstick
*/

#include "../include/my.h"

void turn(map_t *map)
{
    get_answer_user(map);
    get_answer_match(map);
}
void check_match(map_t *map)
{
    if (map->num < 0) {
        my_printf("Error: invalid input (positive number expected)\n");
        turn(map);
    }
    if (check_line(map) < map->num && map->num > 0) {
        my_printf("Error: not enough matches on this line\n");
        turn(map);
    }
    if (map->num > map->nbr) {
        my_printf("Error: you cannot remove more than %i ",map->nbr);
        my_printf("matches per turn\n");
        turn(map);
    }
    if (map->num == 0) {
        my_printf("Error: you have to remove at least one match\n");
        turn(map);
    }
}
int get_answer_match(map_t *map)
{
    char *str = NULL;
    size_t len = 0;
    ssize_t nread = 0;
    map->num = -1;

    my_printf("Matches: ");
    nread = getline(&str, &len, stdin);
    if (nread == -1) {
        map->exit = 0;
        return (0);
    }
    if (str == NULL)
        map->num = 0;
    if (my_str_isnum(str) == my_strlen(str) - 1)
        map->num = my_getnbr(str);
    check_match(map);
    return (1);
}
int get_answer_user(map_t *map)
{
    char *str = NULL;
    size_t len = 0;
    ssize_t nread = 0;
    map->line = 0;

    my_printf("Line: ");
    nread = getline(&str, &len, stdin);
    if (nread == -1) {
        map->exit = 0;
        return (0);
    }
    if (my_str_isnum(str) == my_strlen(str) - 1 && nread != -1)
        map->line = my_getnbr(str);
    check_num(map);
    return (1);
}
