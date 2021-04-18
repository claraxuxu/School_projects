/*
** EPITECH PROJECT, 2019
** header file
** File description:
** prototypes of all the functions in lib
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#ifndef MY_H_
#define MY_H_
typedef struct bsq{
    int x;
    int y;
    int fd;
    int size;
    int len;
    char *buf;
    int row;
    int line;
    char **matrix;
    int max_size;
}bsq_t;
void my_putchar(char c);
int my_strlen(char const *str);
void my_putstr(char const *str);
int line_nums(bsq_t *bsq);
int row_nums(bsq_t *bsq);
void generatematrix(bsq_t *bsq);
int maximalsquare(bsq_t *bsq);
void changematrix(bsq_t *bsq);
#endif
