/*
** EPITECH PROJECT, 2019
** reflection
** File description:
** for 102architect reflection part
*/

#include "../include/my.h"

int reflection(char **av)
{
    int d = 2 * atoi(av[4]);
    float x = cos(DegToRad(d));
    float y = sin(DegToRad(d));
    float z = -x; 
    float dx = x * atof(av[1]) + y * atof(av[2]);
    float dy = y * atof(av[1]) - x * atof(av[2]);

    printf("Reflection over an axis with an inclination angle");
    printf(" of %s degrees\n",av[4]);
    printf("%.2f\t%.2f\t0.00\n",x,y);
    printf("%.2f\t%.2f\t0.00\n",y,z);
    printf("0.00\t0.00\t1.00\n");
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n",atof(av[1]),atof(av[2]),dx,dy);
}