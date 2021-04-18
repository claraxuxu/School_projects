/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "defender.h"

void my_putstr(char *s)
{
    write(1, s, my_strlen(s));
}

char *my_strdup(char *s)
{
    int len_string = my_strlen(s);
    char *result = (void *)0;

    if (len_string == 0)
        return ((void *)0);
    result = malloc(sizeof(char) * (len_string + 1));
    for (int i = 0; s[i] != '\0'; i++)
        result[i] = s[i];
    result[len_string] = '\0';
    return (result);
}

int my_nblen(int nb)
{
    int result = 0;

    nb = nb < 0 ? nb * -1 : nb;
    if (nb == 0)
        return (0);
    for (; nb > 0; nb = nb / 10)
        result++;
    return (result);
}

char *my_itoa(int nb)
{
    int nb_len = my_nblen(nb);
    char *result = (void *)0;
    bool is_negative = nb < 0 ? true : false;

    if (nb == 0)
        return (my_strdup("0"));
    result = malloc(sizeof(char) * (nb_len + 1));
    nb = is_negative == true ? nb * -1 : nb;
    result[nb_len] = '\0';
    for (int i = nb_len - 1; i > -1; i--) {
        result[i] = (nb % 10) + 48;
        nb = nb / 10;
    }
    return (is_negative == true ? my_strcat("-", result) : result);
}

int my_atoi(char *src)
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