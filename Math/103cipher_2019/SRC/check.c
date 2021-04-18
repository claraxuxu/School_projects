/*
** EPITECH PROJECT, 2019
** cipher_4
** File description:
** for 103cipher 0_4 part
*/

#include "../include/my.h"

int check_num(char *av)
{
    int j = 0;
    int i = 0;

    for (; i < my_strlen(av);i++) {
        if (av[i] != ' ' && isnum(av[i]) == 0)
            j++;
    }
    return (j);
}
int check_alpha(char *av)
{
    int j = 0;
    int i = 0;

    for (; i < my_strlen(av);i++) {
        if (av[i] != ' ' && isnum(av[i]) > 0)
            j++;
    }
    return (j);
}