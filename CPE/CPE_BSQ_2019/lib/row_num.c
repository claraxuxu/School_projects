/*
** EPITECH PROJECT, 2019
** row_num
** File description:
** row num of buffer
*/

#include "../include/my.h"

int row_nums(bsq_t *bsq)
{
    int i = 0;

    bsq->row = 0;
    while (bsq->buf[i] != '\n')
        i++;
    for (int j = 0; j <= i - 1; j++)
        bsq->row = bsq->row * 10 + bsq->buf[j] - '0';
    line_nums(bsq);
}
int line_nums(bsq_t *bsq)
{
    int i = 0;
    int j = 0;

    while (bsq->buf[i] != '\n')
        i++;
    j = i;
    i++;
    while (bsq->buf[i] != '\n')
        i++;
    bsq->line = i - j - 1;
}
