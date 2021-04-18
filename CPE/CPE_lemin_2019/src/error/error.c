/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** error.c
*/

#include "lemin.h"

int verify(char *str, char search)
{
    int len = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == search)
            len++;
        i++;
    }
    return (len);
}

int start_end(char *buff, char *start_or_end)
{
    char **tmp = my_str_retab(buff);
    int len = 0;

    for (int y = 0; tmp[y]; y++)
        if (my_strcmp(tmp[y], start_or_end) == 1)
            len++;
    return (len);
}

int check_anthil(char *buff)
{
    if (buff == NULL)
        return -1;
    if (verify(buff, '\n') <= 2)
        return -1;
    if (verify(buff, '-') <= 1)
        return -1;
    if (start_end(buff, "##start") != 1 || start_end(buff, "##end") != 1)
        return -1;
    return 0;
}

int my_error(char *buff)
{
    if (check_anthil(buff) == -1)
        return -1;
    if (stock_room(buff) == -1)
        return -1;
    if (check_tunnel(buff) == -1)
        return -1;
    return 0;
}