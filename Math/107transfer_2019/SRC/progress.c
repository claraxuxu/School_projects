/*
** EPITECH PROJECT, 2019
** 107transfer_2019
** File description:
** progress.c
*/

#include "../include/my.h"

double process_horner(char *str, double x)
{
	int pos_begin = strlen(str) - 1;
	int pos_end = pos_begin;
	double value = 0;
	char *buff;

	while (pos_begin >= 0) {
		pos_end = pos_begin;
		for (; pos_begin >= 0 && str[pos_begin] != '*'; pos_begin--);
		pos_begin++;
		buff = my_strdup(str + pos_begin);
		buff[pos_end - pos_begin + 1] = 0;
		value *= x;
		value += atoi(buff);
		pos_begin -= 2;
	}
	return (value);
}

void progress(math_t *math)
{
	double res = 1;

	for (double value = 0; value < 1.001; value += 0.001) {
		for (int i = 0; i < math->ac; i += 2)
			res *= process_horner(math->num[i], value) / 
			process_horner(math->num[i + 1], value);
		printf("%.3f -> %.5f\n", value, res);
		res = 1;
	}
}
