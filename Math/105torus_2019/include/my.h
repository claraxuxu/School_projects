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
    int opt;
    int a0;
    int a1;
    int a2;
    int a3;
    int a4;
    double n;
    double pt1;
    double pt2;
    double xm1;
    double xm2;
    double xm;
    double xn;
    double x;
    double xn1;
    double xn2;
}num_t;


int my_strlen(char const *str);
int my_str_isnum(char const *str);
int help();
int change_to_num(num_t *num, char **av);
//disection methode
int disec_metho(num_t *num);
void disec_metho_two(num_t *num);

//newton methode
void newton_metho_two(num_t *num);
int newton_metho(num_t *num);

//secant methode
int secant_metho(num_t *num);
void secant_metho_two(num_t *num);
#endif
