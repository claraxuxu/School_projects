/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** find_char.c
*/

#include "tetris.h"

int find_char(char *str, char find)
{
    int num = 0;

    if (str == NULL)
        return num;
    for (int i = 0; str[i]; i++)
        if (str[i] == find)
            num++;
    return (num);
}
