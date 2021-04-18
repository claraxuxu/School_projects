/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenate two strings
*/

#include "../include/my.h"

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

char *my_strdup(char *src)
{
    char *p_src = NULL;
    int count = 0;
    char *new_addr;

    if (src == NULL)
        return (NULL);
    p_src = src;
    while (*p_src != '\0') {
        count++;
        p_src++;
    }
    new_addr = malloc(sizeof(char) * (count + 1));
    p_src = src;
    while (*p_src  != '\0')
        *new_addr++ = *p_src++;
    *new_addr = '\0';
    return (new_addr - (count));
}