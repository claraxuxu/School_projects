/*
** EPITECH PROJECT, 2019
** game
** File description:
** game part
*/

#include "my.h"

int game1(file_t *file)
{
    if (file->turn > 1 && file->turn % 2 != 0 && file->win == 0)
        put_map(file);
    if (file->turn % 2 != 0) {
        file->id = file->id2;
        get_answer_user(file);
        get_res(file);
        pause();
        attack_change(file);
        check_win(file);
        file->turn++;
    }
    if (file->turn % 2 == 0) {
        if (file->exit == 1)
            return (1);
        ask_ans_alpha(file);
        file->id = file->id2;
        check_attack(file);
        check_win(file);
        file->turn++;
    }
}

int game2(file_t *file)
{
    if (file->turn % 2 == 0 && file->win == 0) {
        file->id = file->id1;
        get_answer_user(file);
        get_res(file);
        pause();
        attack_change(file);
        put_map(file);
        check_win(file);
        file->turn++;
    }
    if (file->turn % 2 != 0) {
        if (file->exit == 1)
            return (1);
        ask_ans_alpha(file);
        file->id = file->id1;
        check_attack(file);
        check_win(file);
        file->turn++;
    }
}
