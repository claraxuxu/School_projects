/*
** EPITECH PROJECT, 2020
** check_if_end_loop.c
** File description:
** check if end loop
*/

#include <unistd.h>
#include "api_answer.h"
#include "macros.h"
#include "loop.h"
#include "lib.h"

bool_t is_ok(answer_t ans)
{
    float *lidar = NULL;

    if (ans.value == SIM_NOT_LAUNCHED || ans.value == CAM_ERR ||
    (ans.value >= 20))
        return FALSE;
    lidar = extract_float_tab(ans.data);
    for (int i = 0; i < 32; i++)
        if (lidar[i] == 0)
            return FALSE;
    return ans.is_ok;
}

inline bool_t is_over(answer_t ans)
{
    return (ans.misc_info == TRACK_CLEARED ? TRUE : FALSE);
}