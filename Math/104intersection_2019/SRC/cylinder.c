/*
** EPITECH PROJECT, 2019
** cylinder
** File description:
** for 104intersection cylinder part
*/

#include "../include/my.h"
#include <float.h>

int del_plus(num_t *num)
{
    num->x1 = (-num->b + sqrt(num->del)) / (2 * num->a);
    num->x2 = (-num->b - sqrt(num->del)) / (2 * num->a);
    printf("2 intersection points:\n");
    printf("(%.3f, ",num->xp + num->x1 * num->xv);
    printf("%.3f, ",num->yp + num->x1 * num->yv);
    printf("%.3f)\n",num->zp + num->x1 * num->zv);
    printf("(%.3f, ",num->xp + num->x2 * num->xv);
    printf("%.3f, ",num->yp + num->x2 * num->yv);
    printf("%.3f)\n",num->zp + num->x2 * num->zv);
}
int cylinder(num_t *num)
{
    float x = num->xp + num->x1 * num->xv;

    if (num->del > 0)
        del_plus(num);
    if (num->del == 0) {
        num->x1 = -num->b / (2 * num->a);
        printf("1 intersection point:\n");
        printf("(%.3f, %s, %s)\n",x,"0.000","0.000");
    }
    if (num->del < 0)
        printf("No intersection point.\n");
}