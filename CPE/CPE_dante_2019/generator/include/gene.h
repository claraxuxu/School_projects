/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** gene.h
*/

#ifndef _GENE_H_
#define _GENE_H_

#include "../../outils/include/my.h"

typedef struct gene{
    int high;
    int width;
    int perfect;
    char **map;
}gene_t;

void init(gene_t *gene, int ac, char **av);
void prepare_stable_map(gene_t *gene);
void pro_perfect(gene_t *gene);
void pro_imperfect(gene_t *gene);
void output_map(gene_t *gene);

#endif