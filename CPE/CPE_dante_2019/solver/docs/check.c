/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** check.c
*/

#include "../include/sol.h"

int check(sol_t *sol, int ac, char **av)
{
    char *filepath = my_strdup(av[1]);
    int fd = 0;

    sol->width = 0;
    if (ac != 2 || filepath == NULL)
        return (-1);
    if ((fd = open(filepath, O_RDONLY)) == -1)
        return (-1);
    sol->size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    sol->buf = malloc(sizeof(char) * sol->size + 1);
    if (sol->buf == NULL || sol->size == 0)
        return (-1);
    read(fd, sol->buf, sol->size);
    sol->buf[sol->size] = '\0';
    for (sol->width = 0; sol->buf[sol->width] != '\n'; sol->width++);
    for (int i = 0; i < sol->size; i++)
        if (sol->buf[i] != '*' && sol->buf[i] != 'X' && sol->buf[i] != '\n')
            return (-1);
    return (0);
}
