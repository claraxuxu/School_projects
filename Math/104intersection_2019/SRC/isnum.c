/*
** EPITECH PROJECT, 2019
** isnum
** File description:
** for 104intersection
*/

#include "../include/my.h"

int isnum(int ac,char **av)
{
    int test = 0;
    
    for (int i = 1; i < ac; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] >= '0' && av[i][j] <= '9')
                test++;
            else if (av[i][j] == '-' && av[i][j + 1] >= '0' &&
                      av[i][j + 1] <= '9') {
                test++;
                j++;
            }
        }
    }
    return (test);
}
