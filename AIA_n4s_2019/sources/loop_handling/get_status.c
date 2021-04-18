/*
** EPITECH PROJECT, 2020
** get_satus.c
** File description:
** get car position, direction, etc...
*/

#include "api_answer.h"
#include "macros.h"
#include "loop.h"
#include "api_quest.h"

status_t get_status(answer_t *ans)
{
    status_t stat = init_status();

    *ans = get_answer("lidar", 0, 0);
    return (stat);
}