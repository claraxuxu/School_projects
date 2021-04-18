/*
** EPITECH PROJECT, 2019
** check_str
** File description:
** check str whether is a num
*/

#include "../include/my.h"

int my_str_isnum(char const *str)
{
	int i = 0;
	int result = 0;

	for (i = 0; str[i] != '\0'; i++) {
		if ((str[i] <= '9' && str[i] >= '0') || str[i] == '-')
			result = 1;
		else
			return (0);
	}
	return (result);
}