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

typedef struct la{
    int *la;
    int *lb;
    int i;
}la_t;

void my_putchar(char c);
int isnum(int ac, char **av);
int my_len(char const *str);
void my_putstr(char const *str);
int my_strlen(int const *str);
int check_la(la_t *list);
void check_a(la_t *list);
void check_b(la_t *list);
void sa(la_t *list);
void sb(la_t *list);
void sc(la_t *list);
void ra(la_t *list);
void rb(la_t *list);
void rr(la_t *list);
void rra(la_t *list);
void rrb(la_t *list);
void rrr(la_t *list);
void pa(la_t *list);
void pb(la_t *list);
#endif