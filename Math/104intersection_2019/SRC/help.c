/*
** EPITECH PROJECT, 2019
** help
** File description:
** for 104intersection help part
*/

#include "../include/my.h"

int help()
{
    printf("USAGE\n");
    printf("    ./104intersection opt xp yp zp xv yv zv p\n\n");
    printf("DESCRIPTION\n");
    printf("    opt\t\t    surface option: 1 for a sphere, 2 for a cylinder,");
    printf(" 3 for a cone\n    (xp, yp, zp)    coordinates of a point by ");
    printf("which the light ray passes through\n    (xv, yv, zv)    ");
    printf("coordinated of a vector parallel to the light ray\n");
    printf("    p\t\t    parameter: radius of the sphere, radius of the ");
    printf("cylinder, or angle formed by the cone and the Z-axis\n");
}