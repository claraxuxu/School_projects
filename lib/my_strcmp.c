/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** task06
*/

#include "include/my.h"

int my_strcmp(char *str1, char *str2)
{
    for (; *str1 != '\0'; str1++, str2++) {
        if (*str1 != *str2) {
            if (*str1 > *str2)
                return (1);
            else if (*str1 < *str2)
                return (-1);
        }
    }
    if (*str1 == '\0' || *str2 == '\0') {
        if (*str1 > *str2)
            return (1);
        else if (*str1 < *str2)
            return (-1);
        return (0);
    }
}

int my_strncmp(char *str1, char *str2, int len)
{
    for (int i = 0; i < len; i++)
        if (str1[i] != str2[i])
            return (-1);
    return (0);
}
