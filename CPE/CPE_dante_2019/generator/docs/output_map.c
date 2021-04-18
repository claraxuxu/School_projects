/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** output_map.c
*/

#include "gene.h"

void output_map(gene_t *gene)
{
    for (int i = 0; i < gene->high - 1; i++)
        printf("%s\n",gene->map[i]);
    printf("%s",gene->map[gene->high - 1]);
}