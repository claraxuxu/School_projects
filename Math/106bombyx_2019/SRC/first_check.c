/*
** EPITECH PROJECT, 2019
** first_check
** File description:
** second option for 106
*/

#include "../include/my.h"

void process_first(char **av, num_t *num)
{
    double x = 0;

    num->n = atoi(av[1]);
    num->k = atof(av[2]);
    x = num->n;
    for (int i = 1; i <= 100; i++) {
		printf("%d %.2f\n", i, x);
		x = num->k * x * ((1000 - x) / 1000);
	}
}
void first_check(char **av)
{
    num_t num;
    if (my_str_isnum(av[1]) != 1 || my_num(av[2]) != 1)
        exit (84);
    if (atof(av[2]) > 4 || atof(av[2]) < 1 || atoi(av[1]) < 1)
        exit (84);
    process_first(av, &num);
}