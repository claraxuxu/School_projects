/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** my_strdup.c
*/

#include "../include/my.h"

char *my_strdup(char *src)
{
    char *p_src = NULL;
    int count = 0;
    char *new_addr;

    if (src == NULL)
        return (NULL);
    p_src = src ;
    while (*p_src != '\0') {
        count++;
        p_src++;
    }
    new_addr = malloc(sizeof(char)* (count + 1));
    p_src = src;
    while (*p_src  != '\0')
        *new_addr++ = *p_src++;
    *new_addr = '\0';
    return (new_addr - (count));
}

int *my_intdup(int *src)
{
    int *p_src = NULL;
    int count = 0;
    int *new_addr;

    if (src == NULL)
        return (NULL);
    p_src = src ;
    while (*p_src != '\0') {
        count++;
        p_src++;
    }
    new_addr = malloc(sizeof(int)* (count + 1));
    p_src = src;
    while (*p_src  != '\0')
        *new_addr++ = *p_src++;
    *new_addr = '\0';
    return (new_addr - (count));
}