/*
** EPITECH PROJECT, 2019
** traslation
** File description:
** for 102architect translation part
*/

#include <stdio.h>
#include <stdlib.h>

int translation(char **av)
{
    float x;
    float y;

    x = atof(av[1]) * 1.00 + atof(av[2]) * 0.00 + 1.00 * atof(av[4]);
    y = atof(av[1]) * 0.00 + atof(av[2]) * 1.00 + 1.00 * atof(av[5]);
    printf("Translation along vector (%s, %s)\n",av[4],av[5]);
    printf("1.00\t0.00\t%.2f\n",atof(av[4]));
    printf("0.00\t1.00\t%.2f\n",atof(av[5]));
    printf("0.00\t0.00\t1.00\n");
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n",atof(av[1]),atof(av[2]),x,y);
}