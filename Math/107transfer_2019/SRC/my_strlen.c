/*
** EPITECH PROJECT, 2019
** 107transfer_2019
** File description:
** my_strlen.c
*/

#include "../include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}