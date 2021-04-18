/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** task02
*/

#include <unistd.h>

int my_strlen(char *str);

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
    return (0);
}
