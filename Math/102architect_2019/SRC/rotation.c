/*
** EPITECH PROJECT, 2019
** rotation
** File description:
** for 102architect rotation part
*/

#include "../include/my.h"

int rotation(char **av)
{
    int d = atoi(av[4]);
    float x = cos(DegToRad(d));
    float y = sin(DegToRad(d));
    float z; 
    float dx = x * atof(av[1]) - y * atof(av[2]);
    float dy = y * atof(av[1]) + x * atof(av[2]);

    if (y > 0 || y < 0)
        z = -y;
    else if (y == 0)
        z = 0;
    printf("Rotation by a %s degree angle\n",av[4]);
    printf("%.2f\t%.2f\t0.00\n",x,z);
    printf("%.2f\t%.2f\t0.00\n",y,x);
    printf("0.00\t0.00\t1.00\n");
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n",atof(av[1]),atof(av[2]),dx,dy);
}