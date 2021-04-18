/*
** EPITECH PROJECT, 2019
** header file
** File description:
** prototypes of all the functions in lib
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#ifndef MY_H_
#define MY_H_

typedef struct math{
    char **num;
    int ac;
}math_t;

char *my_strdup(char *src);
int my_str_isnum(char const *str);
void help_part(void);
int check_part(int ac, char **av);
int my_strlen(char *str);
void progress(math_t *math);
#endif
