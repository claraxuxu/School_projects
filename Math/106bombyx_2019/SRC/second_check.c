/*
** EPITECH PROJECT, 2019
** second_check
** File description:
** second option for 106
*/

#include "../include/my.h"

void process_second(char **av, num_t *num)
{
    num->n = atoi(av[1]);
    num->i0 = atof(av[2]);
    num->i1 = atof(av[3]);
    double k = 1;
	double x = num->n;

	for (k = 1; k <= 4; k += 0.01) {
		for (int i = 1; i <= num->i1; i++) {
			while (i < num->i0) {
				x = k * x * ((1000 - x) / 1000);
				i++;
			}
			x = k * x * ((1000 - x) / 1000);
			printf("%.2f %.2f\n", k, x);
		}
	}
}
void second_check(char **av)
{
    num_t num;
    if (my_str_isnum(av[1]) != 1 || my_str_isnum(av[2]) != 1 
    || my_str_isnum(av[3]) != 1)
        exit (84);
    if ((atof(av[2]) <=  atof(av[1])) || atof(av[1]) < 1)
        exit (84);
    process_second(av, &num);
}