/*
** EPITECH PROJECT, 2019
** my_str_isnum.c
** File description:
** task01
*/

#include <unistd.h>

void my_putchar(char c);

int my_str_isnum(char const *str)
{
    if (str == NULL)
        return (0);
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] < '0' || str[a] > '9')
            return (0);
    }
    return (1);
}
