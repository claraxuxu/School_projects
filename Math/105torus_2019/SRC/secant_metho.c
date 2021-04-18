/*
** EPITECH PROJECT, 2020
** secant_metho
** File description:
** secant methode for 105torus
*/

#include "../include/my.h"

void secant_metho_two(num_t *num)
{
    num->xn1 = num->a4 * pow(num->pt1, 4) + num->a3 * pow(num->pt1, 3) +
        num->a2 * pow(num->pt1, 2) + num->a1 * num->pt1 + num->a0;
    num->xn2 = num->a4 * pow(num->pt2, 4) + num->a3 * pow(num->pt2, 3) +
        num->a2 * pow(num->pt2, 2) + num->a1 * num->pt2 + num->a0;
    if ((num->xn2 - num->xn1) == 0)
        exit (84);
}
int secant_metho(num_t *num)
{
    num->pt1 = 0;
    num->pt2 = 1;
    int n = num->n;

    for (int i = 1; i < 200; ++i) {
        if (round(num->pt1 * pow(10, num->n)) ==
            round(num->pt2 * pow(10, num->n)))
            break;
        secant_metho_two(num);
        num->x = num->pt2 - (num->xn2 * (num->pt2 - num->pt1) /
                             (num->xn2 - num->xn1));
        if (i != 1)
            printf("x = %.*lf\n", n, num->x);
        else
            printf("x = %.1f\n", num->x);
        num->pt1 = num->pt2;
        num->pt2 = num->x;
    }
}
