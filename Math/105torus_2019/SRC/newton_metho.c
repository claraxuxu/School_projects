/*
** EPITECH PROJECT, 2020
** newton_metho
** File description:
** newton methode for 105torus
*/


#include "../include/my.h"

void newton_metho_two(num_t *num)
{
    num->xn1 = num->a4 * pow(num->xn, 4) + num->a3 * pow(num->xn, 3) +
        num->a2 * pow(num->xn, 2) + num->a1 * num->xn + num->a0;
    num->xn2 = 4 * num->a4 * pow(num->xn, 3) +
        3 * num->a3 * pow(num->xn, 2) + 2 * num->a2 * num->xn + num->a1;
    if (num->xn2 == 0)
        exit (84);
    num->x = num->xn - (num->xn1 / num->xn2);
}
int newton_metho(num_t *num)
{
    num->xn = 0.5;
    int n = num->n;

    for (int i = 1; i < 100; ++i) {
        newton_metho_two(num);
        if (round(num->xn * pow(10, num->n)) ==
            round(num->x * pow(10, num->n)))
            break;
        if (i == 1)
            printf("x = %.1f\n", num->x);
        printf("x = %.*lf\n", n, num->x);
        num->xn = num->x;
    }
}
