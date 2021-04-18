/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** map_imperfect.c
*/

#include "../include/gene.h"

void more_road(gene_t *gene)
{
    for (int i = 1; i < gene->high; i += 2)
        for (int j = 1; j < gene->width; j += 2) {
            if (gene->map[i][j] == 'X')
                if (rand () % 4)
                    gene->map[i][j] = '*';
        }
}

void pro_imperfect(gene_t *gene)
{
    prepare_stable_map(gene);
    for (int i = 0; i < gene->high; i += 2) {
        for (int j = 0; j < gene->width; j += 2) {
            gene->map[i][j] = '*';
            if (i != 0 && j != 0) {
                if (rand() % 4 > 1) gene->map[i - 1][j] = '*';
                else gene->map[i][j - 1] = '*';
            }
        }
        if (!(gene->high % 2) || !(gene->width % 2)) {
            if (rand() % 4 > 1)
                gene->map[gene->high - 2][gene->width - 1] = '*';
            else gene->map[gene->high - 1][gene->width - 2] = '*';
        }
    }
    gene->map[gene->high - 1][gene->width - 1] = '*';
    more_road(gene);
}
