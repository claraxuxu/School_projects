/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** task01
*/

#include "../include/my.h"

int my_str_isnum(char const *str)
{
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= '9' && str[i] >= '0')
            result = 1;
        else
            return (0);
    }
    return (result);
}
