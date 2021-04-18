/*
** EPITECH PROJECT, 2019
** process
** File description:
** game process for navy
*/

#include "my.h"

int process2(file_t *file)
{
    check_win(file);
    if (file->win > 0)
        return (1);
    if (game2(file) == 1)
        return (1);
}
int process(file_t *file)
{
    if (file->ac == 2) {
        check_win(file);
        if (file->win > 0)
            return (1);
        if (game1(file) == 1)
            return (1);
    }
    if (file->ac == 3) {
        if (process2(file) == 1)
            return (1);
    }
}