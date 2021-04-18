/*
** EPITECH PROJECT, 2019
** check.c
** File description:
** gestion d'erreur
*/

#include "tetris.h"

int check_buf(char *buf, char *first_line)
{
    int star = 0;

    if (my_strlen(buf) < 7 || first_line == NULL)
        return (0);
    if ((my_atoi(first_line[0]) < 0) || (my_atoi(first_line[2]) < 0) ||
        (my_atoi(first_line[4]) <= 0) || (my_atoi(first_line[4]) >= 10))
        return (0);
    for (int i = my_strlen(first_line); buf[i]; i++) {
        if (buf[i] == '*')
            star++;
        if (buf[i] != '*' && buf[i] != ' ' && buf[i] != '\n')
            return (0);
    }
    return (star);
}
