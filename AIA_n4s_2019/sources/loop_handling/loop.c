/*
** EPITECH PROJECT, 2020
** loop.c
** File description:
** main loop
*/

#include "api_answer.h"
#include "macros.h"
#include "loop.h"
#include "lib.h"
#include "api_quest.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

status_t init_status(void)
{
    status_t res = {
        .speed = 0,
        .direction = {0, 0},
        .middle = 0,
        .left = 0,
        .right = 0
    };

    return (res);
}

question_t init_quest(void)
{
    question_t res = {
        .str = NULL,
        .flt = 0,
        .nb = 0
    };

    return (res);
}

int loop(void)
{
    answer_t answer = get_answer("start", 0, 0);
    question_t quest = init_quest();
    bool_t is_forward = TRUE;
    float speed = 0;

    answer = get_answer("forward", .075, 0);
    for (answer_t lidar = init_answer_struct() ;; ) {
        lidar = get_answer("lidar", 0, 0);
        quest = get_wheel_angle(lidar, is_forward);
        answer = get_answer(quest.str, quest.flt, quest.nb);
        quest = get_car_speed(get_answer("lidar", 0, 0), &is_forward);
        answer = get_answer(quest.str, quest.flt, quest.nb);
        if (is_over(answer)) {
            answer = get_answer("stop", 0, 0);
            break;
        }
    }
    return (0);
}
