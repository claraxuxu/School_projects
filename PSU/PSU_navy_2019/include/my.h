/*
** EPITECH PROJECT, 2019
** struct
** File description:
** navy
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#ifndef _MY_H
#define _MY_H

#define READ_SIZE 2000
int id2;

typedef struct file {
    int exit;
    int win;
    char a;
    int pos1;
    int pos2;
    int status;
    int turn;
    pid_t id;
    pid_t id1;
    pid_t id2;
    int ac;
    int size;
    int fd;
    char *buf;
    int user[2][1];
    int tab[4][6];
    char blank[8][8];
    char sec_map[8][8];
    int len;
}file_t;

//printf and basic fonctions
void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_getnbr(char *str);
int my_atoi(char src);
int my_atoistr(char *src);
int my_str_isalpha(char str);
char my_strncpy(char *res, char *line, int len);
int my_str_isnum(char str);
int my_str_isnump(char *str);
int my_printf(char *format,...);

//game basic part
void help_part(void);
int read_file(char *filepath, file_t *file);
int make_connection(file_t *file, char **av);
int check_map(char *buf);
int build_tab(file_t *file);
void build_map(file_t *file);
void put_map(file_t *file);

//game main part
int get_answer_user(file_t *file);
int game1(file_t *file);
int game2(file_t *file);
void ask_ans_alpha(file_t *file);
void check_attack(file_t *file);
void get_res(file_t *file);
int check_win(file_t *file);
int process(file_t *file);
void attack_change(file_t *file);

#endif
