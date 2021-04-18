/*
** EPITECH PROJECT, 2019
** tunnel.c
** File description:
** lem-in
*/

#include "lemin.h"

int char_is_num(char **tmp, int y, int x)
{
    for (y = 0; tmp[y]; y++)
        for (x = 0; x < my_strlen(tmp[y]); x++)
            if (tmp[y][x] <= 57 && tmp[y][x] >= 48)
                return 1;
    return 0;
}

int share_to_tunnel(char **tmp, int y, int x)
{
    if (char_is_num(tmp, y, x) == 1 && tmp[y][x + 1] == '-'
        && char_is_num(tmp, y, x + 2) == 1)
        if (tmp[y][x] == tmp[y][x + 2])
            return -1;
    return 0;
}

int check_tunnel(char *buff)
{
    char **tmp = my_str_retab(buff);

    for (int y = 0; tmp[y]; y++)
        for (int x = 0; x < my_strlen(tmp[y]); x++)
            if (share_to_tunnel(tmp, y, x) == -1)
                return -1;
    return 0;
}
