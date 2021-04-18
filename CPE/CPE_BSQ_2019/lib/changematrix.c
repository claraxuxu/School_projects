/*
** EPITECH PROJECT, 2019
** changematrix
** File description:
** change matrix by x
*/

#include "../include/my.h"

void changematrix(bsq_t *bsq)
{
    int j = bsq->y;
    int t = 0;

    for(int i = bsq->x; i < (bsq->x + bsq->max_size) && i < bsq->row; i++) {
        j = bsq->y;
        for(; j < (bsq->y + bsq->max_size) && j < bsq->line; j++) {
            bsq->matrix[i][j] = 'x';
            t++;
        }
    }
}
