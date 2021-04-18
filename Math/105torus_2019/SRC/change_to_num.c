/*
** EPITECH PROJECT, 2019
** change_to_num
** File description:
** for 105torus char->int part
*/

#include "../include/my.h"

int change_to_num(num_t *num, char **av)
{
    num->opt = atoi(av[1]);
    num->a0 = atoi(av[2]);
    num->a1 = atoi(av[3]);
    num->a2 = atoi(av[4]);
    num->a3 = atoi(av[5]);
    num->a4 = atoi(av[6]);
    num->n = atof(av[7]);
}
