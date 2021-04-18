/*
** EPITECH PROJECT, 2019
** first_check
** File description:
** second option for 107
*/

#include "../include/my.h"

int check_syntax(char *av)
{
	int start = my_strlen(av) - 1;
	int end;
	char *buff;

	if (start < 0)
		return (-1);
	while (start >= 0) {
		end = start;
		for (; start >= 0 && av[start] != '*'; start--);
		start++;
		buff = strdup(av + start);
		buff[end - start + 1] = 0;
		if (my_str_isnum(buff) == 0)
			return (-1);
		start -= 2;
		if (start == -1)
			return (-1);
	}
	return (1);
}

int check_part(int ac, char **av)
{
	if ((ac - 1) % 2 != 0)
		return (-1);
	for (int i = 1; i < ac; i++)
		if (check_syntax(av[i]) == -1)
			return (-1);
	return (1);
}