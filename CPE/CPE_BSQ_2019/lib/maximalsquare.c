/*
** EPITECH PROJECT, 2019
** maximalsquare
** File description:
** get max size
*/

#include "../include/my.h"

int maximalsquare(bsq_t *bsq)
{
    int **dp = malloc(sizeof(int*) * bsq->row);

    for (int i = 0; i < bsq->row; i++)
        dp[i] = malloc(sizeof(int) * bsq->line);
    bsq->max_size = 0;
    for (int i = 0; i < bsq->row; i++) {
        for (int j = 0; j < bsq->line; j++) {
            if (bsq->matrix[i][j] == '.') {
                dp[i][j] = MIN(i > 0 && j > 0 ? dp[i - 1][j - 1] : 0,
                               MIN(j > 0 ? dp[i][j - 1] : 0, i > 0 ?
                                   dp[i-1][j] : 0)) + 1;
                if (bsq->max_size < dp[i][j]) {
                    bsq->max_size = dp[i][j];
                    bsq->x = i - bsq->max_size + 1;
                    bsq->y = j - bsq->max_size + 1;
                }
            } else
                dp[i][j] = 0;
        }
    }
}
