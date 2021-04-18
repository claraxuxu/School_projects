/*
** EPITECH PROJECT, 2019
** scaling
** File description:
** for 102architect scaling part
*/

#include <stdio.h>
#include <stdlib.h>

int scaling(char **av)
{
    float x;
    float y;

    x = atof(av[4]) * atof(av[1]) + atof(av[2]) * 0.00 + 1.00 * 0.00;
    y = atof(av[1]) * 0.00 + atof(av[2]) * atof(av[5]) + 1.00 * 0.00;
    printf("Scaling by factors %s and %s\n",av[4],av[5]);
    printf("%.2f\t0.00\t0.00\n",atof(av[4]));
    printf("0.00\t%.2f\t0.00\n",atof(av[5]));
    printf("0.00\t0.00\t1.00\n");
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n",atof(av[1]),atof(av[2]),x,y);
}