/*
** EPITECH PROJECT, 2020
** loop.h
** File description:
** handles loop
*/

#include "structures.h"

#ifndef LOOP_H
#define LOOP_H

// loop.c
status_t init_status(void);
int loop(void);

// get_status.c
status_t get_status(answer_t *);
question_t init_quest(void);

// check_if_end_loop.c
bool_t is_ok(answer_t);
bool_t is_over(answer_t);

#endif