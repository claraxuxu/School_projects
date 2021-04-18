/*
** EPITECH PROJECT, 2019
** check_error
** File description:
** check part for sokoban
*/

#include "../include/my.h"

int check_char(soko_t data)
{
    int error = 0;

    for (int i = 0; data.buf[i] != '\0'; i++) {
        if (data.buf[i] != ' ' && data.buf[i] != '\n' &&
            data.buf[i] != '#' && data.buf[i] != 'X' &&
            data.buf[i] != 'P' && data.buf[i] != 'O')
            error++;
    }
    return (error);
}
int check_situ(soko_t data, check_t *check)
{
    for (int i = 0; data.buf[i] != '\0'; i++) {
        switch (data.buf[i]) {
        case 'P':
            check->p++;
            break;
        case 'X':
            check->x++;
            break;
        case 'O':
            check->o++;
            break;
        default:
            break;
        }
    }
}
int check_error(soko_t data)
{
    check_t check;
    check.p = 0;
    check.x = 0;
    check.o = 0;

    check_situ(data,&check);
    if (check_char(data) > 0 || check.p != 1 || check.x != check.o)
        return (1);
    return(0);
}
