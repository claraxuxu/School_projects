/*
** EPITECH PROJECT, 2019
** receive_answer
** File description:
** get answer hit or not
*/

#include "my.h"

void pos_alpha(int sig)
{
    id2++;
}
void pos_end(int sig)
{
    id2 = 0;
}
void pos_num(int sig)
{
    id2++;
}
void ask_ans_num(file_t *file)
{
    int j = 0;

    if (file->status == 1) {
        signal(SIGUSR1, &pos_num);
        signal(SIGUSR2, &pos_end);
        do {
            pause();
            if (id2 != 0)
                j++;
        }while (id2 > 0);
        file->pos2 = j;
        if (id2 == 0)
            file->status = 0;
    }
}
void ask_ans_alpha(file_t *file)
{
    int i = 0;

    id2 = 0;
    my_printf("waiting for enemy's attack...\n");
    if (file->status == 0) {
        signal(SIGUSR1, &pos_alpha);
        signal(SIGUSR2, &pos_end);
        do {
            pause();
            if (id2 != 0)
                i++;
        }while (id2 > 0);
        file->pos1 = i;
        if (id2 == 0)
            file->status = 1;
    }
    ask_ans_num(file);
}
