/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** init.c
*/

#include "../include/gene.h"

void init(gene_t *gene, int ac, char **av)
{
    gene->perfect = 0;
    gene->high = my_atoi(av[1]);
    gene->width = my_atoi(av[2]);
    if (ac == 4)
        if (my_strcmp(av[3], "perfect") == 0)
            gene->perfect = 1;
    gene->map = malloc(sizeof(char *) * gene->high);
    for (int i = 0; i < gene->high; i++)
        gene->map[i] = malloc(sizeof(char) * gene->width + 1);
    for (int i = 0; i < gene->high; i++) {
        for (int j = 0; j < gene->width; j++)
            gene->map[i][j] = 'X';
        gene->map[i][gene->width] = '\0';
    }
}
