/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** compute_floats.c
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

float get_speed_float(float fwd, float old_speed)
{
    float result = 0;
    float speeds[6] = {0.15, 0.25, 0.35, 0.48, 0.65, 0.75};
    float positions[5] = {200, 400, 850, 1250, 1500};

    if (fwd < positions[0])
        result = speeds[0];
    if (fwd >= positions[0] && old_speed >= speeds[0])
        result = speeds[1];
    if (fwd >= positions[1] && old_speed >= speeds[1])
        result = speeds[2];
    if (fwd >= positions[2] && old_speed >= speeds[2])
        result = speeds[3];
    if (fwd >= positions[3] && old_speed >= speeds[3])
        result = speeds[4];
    if (fwd >= positions[4] && old_speed >= speeds[4])
        result = speeds[5];
    return result;
}

float get_wheel_float(float idx)
{
    float result = 0;
    float indx_tab[6] = {600, 400, 300, 200, 100, 50};
    float angles[6] = {0.025, 0.05, 0.15, 0.35, 0.5, 0.75};

    if (idx <= indx_tab[0])
        result = angles[0];
    if (idx <= indx_tab[1])
        result = angles[1];
    if (idx <= indx_tab[2])
        result = angles[2];
    if (idx <= indx_tab[3])
        result = angles[3];
    if (idx <= indx_tab[4])
        result = angles[4];
    if (idx <= indx_tab[5])
        result = angles[5];
    return result;
}
