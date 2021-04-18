/*
** EPITECH PROJECT, 2020
** map
** File description:
** contains linked lists of map and tetrimino.
*/

#ifndef MAP_H
#define MAP_H


typedef struct line line;
struct line
{
    char *cur_line;
    line *next;
};

typedef struct list
{
    line *first;
} list_t;

typedef struct tetrimino
{
    char **tetrimino;
    char **next_tetrimino;
    list_t *interface;
    list_t *map_calc;
} display_t;

#endif