/*
** EPITECH PROJECT, 2020
** structures.h
** File description:
** project structures
*/

#include "macros.h"
#include "structures.h"
#include <unistd.h>

#ifndef API_ANSWER_H
#define API_ANSWER_H

#ifndef LOGPATH
#define LOGPATH "./input.log"
#endif

// init_data.c
answer_t init_answer_struct(void);
command_t get_user_cmd(char *);

// log_file_handler.c
void create_logpath(cchar_t *);

// get_answer_type.c
answer_t get_answer_type(char *, format_t);
answer_t format_one(char *);
answer_t format_two(char *);
answer_t format_three(char *);
answer_t format_four(char *);

// get_format_types.c
additional_info_t get_additionnal_info(char *);
float *get_float_tab(char **, int *);
float *copy_float_tab(float *);
vector_t get_vector(char *);

// extract_data.c
float extract_float(data_t);
float *extract_float_tab(data_t);
vector_t extract_vector(data_t);

// get_answer.c
answer_t get_answer(char *, float, int);

#endif /* API_ANSWER_H */