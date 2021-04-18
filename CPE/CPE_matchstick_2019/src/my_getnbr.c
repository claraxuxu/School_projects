/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** get nbr from a string
*/

#include "../include/my.h"

int my_getnbr(char *str)
{
    int val = 0;
    int e = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            val *= 10;
            val += str[i] - '0';
        }
        else if (str[i] == '-')
            e = -1;
    }
    return (val * e);
}
