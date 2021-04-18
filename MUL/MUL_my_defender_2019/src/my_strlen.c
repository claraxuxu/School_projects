/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** count str length
*/

#include "defender.h"

int my_strlen(char *s)
{
    int c = 0;

    if (s == NULL)
        return (0);
    for (; s[c]; c++);
    return (c);
}

char *my_strcat(char *str, char *str2)
{
    char *res = malloc(sizeof(char) * my_strlen(str) + my_strlen(str2) + 1);
    int i = 0;

    for (i = 0; i < my_strlen(str); i++)
        res[i] = str[i];
    for (int a = 0; a < my_strlen(str2); a++, i++)
        res[i] = str2[a];
    res[i] = '\0';
    return (res);
}