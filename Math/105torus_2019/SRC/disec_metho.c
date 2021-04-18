/*
** EPITECH PROJECT, 2020
** disec_metho
** File description:
** disection methode for 105torus
*/

#include "../include/my.h"

void disec_metho_two(num_t *num)
{
    num->xm1 = num->a4 * pow(num->xm, 4) + num->a3 * pow(num->xm, 3) +
        num->a2 * pow(num->xm, 2) + num->a1 * num->xm + num->a0;
    num->xm2 = num->a4 * pow(num->pt1, 4) + num->a3 * pow(num->pt1, 3) +
        num->a2 * pow(num->pt1, 2) + num->a1 * num->pt1 + num->a0;
    if (num->xm2 * num->xm1 < 0)
        num->pt2 = num->xm;
    else
        num->pt1 = num->xm;
}
int disec_metho(num_t *num)
{
    num->pt1 = 0;
    num->pt2 = 1;
    int n = num->n;

    for (int i = 1; i < 300; ++i) {
        num->xm = (num->pt1 + num->pt2) / 2;
        if (i <= num->n)
            printf("x = %.*f\n", i, num->xm);
        else
            printf("x = %.*lf\n", n, num->xm);
        disec_metho_two(num);
        if (round(num->pt1 * pow(10, num->n)) ==
            round(num->pt2 * pow(10, num->n)))
            break;
    }
}
