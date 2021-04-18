/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** headers and defines
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#ifndef READ_SIZE
#define READ_SIZE 5
typedef struct get{
    int count;
    char *buf;
    char *line;
    int start;
    int fd;
}get_t;

char *get_next_line(int fd);
char my_strncpy(char *res, char *line, int len);
char copybuf(char *res, char *buff, int count, int len);
char *get_line(char *line, int count, char *buff, int *start);
char *stock_line(char *line, int count, char *buff, int *start);
int check(int fd, int size);

#endif