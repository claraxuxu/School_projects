/*
** EPITECH PROJECT, 2019
** help
** File description:
** for 105torus help part
*/

#include "../include/my.h"

int help(void)
{
    printf("USAGE\n");
    printf("    ./105torus opt a0 a1 a2 a3 a4 n\n\n");
    printf("DESCRIPTION\n");
    printf("    opt\t     method option:\n \t\t 1 for the bisection method\n"); \
    printf("\t\t 2 for Newton's method\n\t\t 3 for the secant method\n");
    printf("    a[0-4]   coefficients of the equation\n");
    printf("    n\t     precision (the application of the polynomial ");
    printf("to the solution should\n\t     be smaller than 10^-n)\n");
}
