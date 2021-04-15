/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copy a string into another
*/

#include "include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int count = 0;
    char const *cpy = src;

    for (cpy = src; *cpy != '\0'; cpy++)
        count ++;
    for (int j = 0; j <= count; j++)
        dest[j] = src[j];
    return (dest);
}

char *my_strncpy(char *res, char *line, int len)
{
    int i = 0;

    if (line == NULL)
        res[0] = '\0';
    else {
        for (; i < len; i++)
            res[i] = line[i];
        res[i] = '\0';
    }
    return (res);
}