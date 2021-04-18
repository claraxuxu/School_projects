/*
** EPITECH PROJECT, 2019
** struct
** File description:
** my_ls
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#ifndef _MY_H
#define _MY_H
#define READ_SIZE 2000
typedef struct map {
    int size;
    int max;
    int nbr;
    int line;
    int exit;
    int num;
    char **match;
    int space;
}map_t;
void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char *str);
char *get_next_line(int fd);
char my_strncpy(char *res, char *line, int len);
int my_str_isnum(char const *str);
//map
char map( map_t *map);
char change_map(map_t *map);
char triangle(map_t *map);
void make_square(map_t *map);

char play(map_t *map);
int get_answer_match(map_t *map);
int get_answer_user(map_t *map);

//check
int check_line(map_t *map);
int check(map_t *map);
void check_num(map_t *map);

//robot
int crand(int a, int b);
char play_bot(map_t *map);

//my_printf
int my_printf(char *format,...);
unsigned long my_pow(int a, int b);
void get_octal(int num);
void get_float(double f);
void res_dif_int(int num, int base);
void get_binary(int num);
void get_float(double f);
void situ_gene(char *begin, va_list arg);
#endif
