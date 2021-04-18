/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** c file
*/

#include "../include/my.h"

char my_strncpy(char *res, char *line, int len)
{
    int i = 0;

    if (line == NULL)
        res[0] = '\0';
    else {
        for (; i < len; i++)
            res[i] = line[i];
        res[i] = '\0';
    }
}
