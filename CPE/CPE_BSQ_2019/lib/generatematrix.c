/*
** EPITECH PROJECT, 2019
** generatematrix
** File description:
** create matrix
*/

#include "../include/my.h"

void generatematrix(bsq_t *bsq)
{
    int cnt = 0;
    int i = -1;
    int j = 0;

    bsq->matrix = malloc(sizeof(int*) * bsq->row);
    for(int i = 0; i < bsq->row; i++)
        bsq->matrix[i] = malloc(sizeof(int) * bsq->line);
    for(int li = 0; li <= bsq->row && cnt <= bsq->size; cnt++) {
        if (bsq->buf[cnt] == '\n') {
            i++;
            j = 0;
            li++;
            continue;
        }
        else if (li >= 1 && j < bsq->line) {
            bsq->matrix[i][j] = bsq->buf[cnt];
            j++;
        }
    }
}
