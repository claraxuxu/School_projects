/*
** EPITECH PROJECT, 2019
** count_buf
** File description:
** len of buf
*/

#include "../include/my.h"

int count_buf(soko_t *data)
{
    data->line = 0;
    data->len_line = 0;

    for (int i = 0; data->buf[i] != '\0'; i++) {
        if (data->buf[i] == '\n')
            data->line++;
    }
    for (; data->buf[data->len_line] != '\n'; data->len_line++);
    for (int i = 0; data->buf[i] != '\0'; i++)
        data->ori[i] = data->buf[i];
}