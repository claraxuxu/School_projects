/*
** EPITECH PROJECT, 2019
** check_attack
** File description:
** check wether the position hit the boat
*/

#include "my.h"

void hit(int sig)
{
    my_putstr(": hit\n\n");
    id2 = 1;
}
void miss(int sig)
{
    my_putstr(": missed\n\n");
    id2 = -1;
}
void attack_change(file_t *file)
{
    if (id2 == 1)
        file->sec_map[file->user[1][0] - 1][file->user[0][0] - 1] = 'x';
    else if (id2 == -1)
        file->sec_map[file->user[1][0] - 1][file->user[0][0] - 1] = 'o';
}
void get_res(file_t *file)
{
    signal(SIGUSR1, &hit);
    signal(SIGUSR2, &miss);
}

void check_attack(file_t *file)
{
    int a = file->pos1 - 1;
    int b = file->pos2 - 1;
    char c = file->pos1 + '0' + 16;

    if (file->blank[b][a] == '.') {
        my_printf("%c%i: missed\n\n",c, file->pos2);
        file->blank[b][a] = 'o';
        kill(file->id, SIGUSR2);
    }
    else if (my_str_isnum(file->blank[b][a]) == 1) {
        file->blank[b][a] = 'x';
        my_printf("%c%i: hit\n\n",c, file->pos2);
        kill(file->id, SIGUSR1);
    }
}
