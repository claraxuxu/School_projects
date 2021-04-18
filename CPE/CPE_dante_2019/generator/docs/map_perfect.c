/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** map_perfect.c
*/

#include "../include/gene.h"

int check_first_ele(int a)
{
    if (a == 0)
        a = a - 1;
    return (a);
}
void prepare_stable_map(gene_t *gene)
{
    for (int i = 0; i < gene->width - 1; i++)
        gene->map[0][i] = '*';
    if (!((gene->width - 1) % 2)) gene->map[0][gene->width - 1] = '*';
    for (int i = 2; i < gene->high; i += 2)
        for (int j = 0; j < gene->width; j++)
            if (!(j % 2)) gene->map[i][j] = '*';
    for (int i = 1; i < gene->high; i += 2)
        if (i + 1 < gene->high) gene->map[i][0] = '*';
}
void pro_perfect(gene_t *gene)
{
    prepare_stable_map(gene);
    for (int i = 0; i < gene->high; i += 2) {
        for (int j = 0; j < gene->width; j += 2) {
            gene->map[i][j] = '*';
            if (i != 0 && j != 0) {
                if (rand() % 3 > 1) gene->map[i - 1][j] = '*';
                else gene->map[i][j - 1] = '*';
            }
        }
        if (!(gene->high % 2) && !(gene->width % 2)) {
            if (rand() % 3 > 1)
                gene->map[gene->high - 2][gene->width - 1] = '*';
            else gene->map[gene->high - 1][gene->width - 2] = '*';
        }
    }
    gene->map[gene->high - 1][gene->width - 1] = '*';
}
