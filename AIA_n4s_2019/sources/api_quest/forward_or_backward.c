/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** forward_or_backward.c
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
#include <string.h>

question_t forward_or_backward(answer_t lidar, bool_t *is_forward)
{
    float *rays = extract_float_tab(lidar.data);
    question_t result = {
        .str = NULL,
        .flt = 0,
        .nb = 0
    };

    for (int i = 0; i < 32; i++) {
        if (rays[i] > 400)
            result.str = my_strdup("forward");
    }
    result.str = result.str == NULL ? my_strdup("backwards") : result.str;
    *is_forward = strcmp(result.str, "forward") == 0 ? TRUE : FALSE;
    return result;
}