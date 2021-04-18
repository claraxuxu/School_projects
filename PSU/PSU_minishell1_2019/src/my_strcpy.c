/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copy a string into another
*/

#include "../include/my.h"

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

