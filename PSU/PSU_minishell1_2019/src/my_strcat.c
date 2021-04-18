/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenate two strings
*/

#include "../include/my.h"

char *my_strcat(char *str, char *str2)
{
    char *res = malloc(sizeof(char) * strlen(str) + strlen(str2) + 1);
    int i = 0;

    for (i = 0; i < strlen(str); i++)
        res[i] = str[i];
    for (int a = 0; a < strlen(str2); a++,i++)
        res[i] = str2[a];
    res[i] = '\0';
    return (res);
}
