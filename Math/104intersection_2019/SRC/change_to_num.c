/*
** EPITECH PROJECT, 2019
** change_to_num
** File description:
** for 104intersection char->int part
*/

#include "../include/my.h"

int change_to_num(num_t *num, char **av)
{
    num->xp = atoi(av[2]);
    num->yp = atoi(av[3]);
    num->zp = atoi(av[4]);
    num->xv = atoi(av[5]);
    num->yv = atoi(av[6]);
    num->zv = atoi(av[7]);
    num->p = atoi(av[8]);
}