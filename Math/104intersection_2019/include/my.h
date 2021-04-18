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
    int xp;
    int yp;
    int zp;
    int xv;
    int yv;
    int zv;
    int p;
    float a;
    float b;
    float c;
    float del;
    float x1;
    float x2;
    float t;
}num_t;

int my_strlen(char const *str);
int isnum(int ac, char **av);
int help();
int change_to_num(num_t *num, char **av);
int sphere(num_t *num);
int cylinder(num_t *num);
int del_plus(num_t *num);
int cone(num_t *num);

#endif
