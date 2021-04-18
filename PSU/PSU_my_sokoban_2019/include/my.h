/*
** EPITECH PROJECT, 2019
** struct
** File description:
** my_sokoban
*/

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#ifndef MY_H_
#define MY_H_
typedef struct sokoban{
    int size;
    char *buf;
    char *ori;
    int fd;
    int len;
    int line;
    int len_line;
    int xp;
    int *xo;
    int *xx;
    int len_o;
}soko_t;
typedef struct check{
    int p;
    int x;
    int o;
}check_t;
int my_strlen (char const *);
int my_putstr(char const *);
int my_put_nbr(int nb);
void my_putchar(char);
void help();
int check_error(soko_t data);
int check_situ(soko_t data, check_t *check);
int check_win(soko_t *data);
void check_o(soko_t *data);
int get_pos(soko_t *data);
int direction(soko_t *data, int c);
int left(soko_t *data);
int right(soko_t *data);
int up(soko_t *data);
int down(soko_t *data);
int count_buf(soko_t *data);
int check_die(soko_t *data);
#endif