/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** get_question.c
*/

#include "api_answer.h"
#include "macros.h"
#include "loop.h"
#include "api_quest.h"
#include "lib.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

float get_forward_float(answer_t answer)
{
    float *tab = extract_float_tab(answer.data);

    return tab[FORWARD];
}

lidar_index_t get_lidindex(answer_t answer)
{
    lidar_index_t result = LEFT;
    float *lidar = extract_float_tab(answer.data);

    return lidar[result] < lidar[RIGHT] ? LEFT : RIGHT;
}

question_t get_car_speed(answer_t answer, bool_t *is_forward)
{
    int fwd = get_forward_float(answer);
    question_t result = forward_or_backward(answer, is_forward);
    static float old_speed = 0.3;

    if (*is_forward == FALSE) {
        old_speed = 0.15;
        result.flt = 0.55;
    } else {
        result.flt = get_speed_float(fwd, old_speed);
        old_speed = result.flt;
    }
    return result;
}

question_t get_wheel_angle(answer_t lidar, bool_t is_forward)
{
    lidar_index_t idx = get_lidindex(lidar);
    bool_t result_is_neg = idx == LEFT ? TRUE : FALSE;
    float *rays = extract_float_tab(lidar.data);
    question_t result = {
        .str = my_strdup("whdir"),
        .flt = 0,
        .nb = 0
    };

    result.flt = get_wheel_float(rays[idx]);
    result.flt = result_is_neg == TRUE ? result.flt : -result.flt;
    result.flt = is_forward == TRUE ? result.flt : result.flt * -1.05;
    return result;
}
