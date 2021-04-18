/*
** EPITECH PROJECT, 2020
** api_quest.h
** File description:
** handles api questionning
*/

#include "structures.h"

#ifndef API_QUEST_H
#define API_QUEST_H

typedef enum LIDAR_INDEX
{
    LEFT = 31, RIGHT = 0, FORWARD = 15, NOLIDINDEX = -1
} lidar_index_t;

// get_question.c
question_t get_question(status_t , answer_t);
question_t get_car_speed(answer_t, bool_t *);
question_t get_wheel_angle(answer_t, bool_t);

// compute_floats.c
float get_speed_float(float fwd, float old_speed);
float get_wheel_float(float idx);

// forward_or_backward.c
question_t forward_or_backward(answer_t, bool_t *);

#endif