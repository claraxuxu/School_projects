/*
** EPITECH PROJECT, 2019
** check_win
** File description:
** win condition for game
*/

#include "my.h"

void get_winner(int a, int b, file_t *file)
{
    if (a >= 14) {
        if (file->ac == 2)
            my_printf("I won\n");
        if (file->ac == 3)
            my_printf("I won\n");
    }
    if (b >= 14) {
        if (file->ac == 2)
            my_printf("Enemy won\n");
        if (file->ac == 3)
            my_printf("Enemy won\n");
    }
}
int check_win(file_t *file)
{
    int a = 0;
    int b = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (file->sec_map[i][j] == 'x')
                a++;
            if (file->blank[i][j] == 'x')
                b++;
        }
    }
    get_winner(a,b,file);
    if (a >= 14 || b >= 14)
        file->exit = 1;
}
