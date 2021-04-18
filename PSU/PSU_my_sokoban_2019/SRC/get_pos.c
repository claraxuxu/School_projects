/*
** EPITECH PROJECT, 2019
** get_pos
** File description:
** get_position of P
*/

#include "../include/my.h"

int get_pos(soko_t *data)
{
    int j = 0;
    data->xo = malloc(sizeof(int*) * 200);
    data->xx = malloc(sizeof(int*) * 200);

    for (int i = 0; data->buf[i] != '\0'; i++) {
        if (data->buf[i] == 'P')
            data->xp = i;
    }
    for (int i = 0; data->buf[i] != '\0'; i++) {
        if (data->buf[i] == 'O') {
            data->xo[j] = i;
            j++;
        }
    }
    for (int i = 0, k = 0; data->buf[i] != '\0'; i++) {
        if (data->buf[i] == 'X') {
            data->xx[k] = i;
            k++;
        }
    }
    data->len_o = j;
}
