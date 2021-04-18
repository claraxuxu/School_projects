/*
** EPITECH PROJECT, 2019
** check_win
** File description:
** check win situation for sokoban
*/

#include "../include/my.h"

int check_die(soko_t *data)
{
    int x = 0;
    int y = data->len_o - 1;

    for (int i = 0; i <= data->len_o; i++) {
        if (data->buf[data->xx[i] + 1] == '#' &&
            (data->buf[data->xx[i] + data->len_line + 1] == '#'||
             data->buf[data->xx[i] - data->len_line - 1] == '#'))
            x++;
        else if (data->buf[data->xx[i] - 1] == '#' &&
                 (data->buf[data->xx[i] + data->len_line + 1] == '#'||
                  data->buf[data->xx[i] - data->len_line - 1] == '#'))
            x++;
    }
    if (x == 2)
        exit (1);
}
int check_win(soko_t *data)
{
    int x = 0;

    for (int i = 0; i <= data->len_o; i++)
        if (data->buf[data->xo[i]] == 'X')
            x++;
    if (x == data->len_o) {
        printw(data->buf);
        clear();
        refresh();
        endwin();
        exit (0);
    }
}
