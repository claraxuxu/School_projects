/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** math_fonc.c
*/

#include "lemin.h"

int my_atoi(char src)
{
    int s = 0;

    if (src >= '0' && src <= '9')
        s = s * 10 + src - '0';
    return (s);
}

int my_atoistr(char *src)
{
    int s = 0;
    int a = 1;

    while (*src == ' ')
        src++;
    if (*src == '+' || *src == '-') {
        if (*src == '-')
            a = -1;
        src++;
    }
    while (*src != '\0' && *src >= '0' && *src <= '9') {
        s = s * 10 + *src - '0';
        src++;
    }
    s = s * a;
    return (s);
}
unsigned long my_pow(int a, int b)
{
    unsigned long res = 1;

    while (b--)
        res *= a;
    return (res);
}