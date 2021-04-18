/*
** EPITECH PROJECT, 2019
** isnum
** File description:
** check part
*/

#include "../include/my.h"

int my_len(char const *str)
{
    int a;

    for (a = 0; str[a]; a++);
    return (a);
}

int isnum(int ac, char **av)
{
    int num = 0;
    int all = 0;

    for (int i = 1; i < ac; i++) {
        for (int j = 0; av[i][j] != '\0'; j++)
            if (av[i][j] >= '0' && av[i][j] <= '9' ||
                (av[i][j] == '-' && av[i][j + 1] >= '0' &&
                av[i][j + 1] <= '9'))
                num++;
    }
    for (int i = 1; i < ac; i++)
        all += my_len(av[i]);
    if (num == all)
        return (1);
    else
        exit (84);
}
