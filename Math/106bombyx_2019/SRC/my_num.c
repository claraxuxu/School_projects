/*
** EPITECH PROJECT, 2019
** check_str
** File description:
** check str whether is a num
*/

#include "../include/my.h"

int my_num(char *str)
{
	for (int i = 0; i < my_strlen(str); i++) {
		if (!(str[i] >= '0' && str[i] <= '9') &&
			str[i] != '.')
			return (0);
	}
	return (1);
}