/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenate two strings
*/

#include "../include/my.h"

char *my_strcat(char *dest, const char *src)
{
    char *tmp = dest;

    while (*dest)
        dest++;
    while ((*dest++ = *src++) != '\0');
    return (tmp);
}
