/*
** EPITECH PROJECT, 2019
** header file
** File description:
** prototypes of all the functions in lib
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef MY_H_
#define MY_H_

typedef struct num{
    int n;
    float k;
    int i0;
    int i1;
}num_t;

int my_strlen(char const *str);
int my_str_isnum(char const *str);
void help(void);
int my_num(char *str);
void first_check(char **av);
void second_check(char **av);
#endif
