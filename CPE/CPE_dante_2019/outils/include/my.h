/*
** EPITECH PROJECT, 2019
** struct
** File description:
** dante
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

//printf and basic fonctions
void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_getnbr(char *str);
int my_atoi(char *src);
int my_atoic(char src);
int my_str_isalpha(char str);
void my_strncpy(char *res, char *line, int len);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char *str1, char *str2);
char *my_strcat(char *dest, const char *src);
char **my_str_to_word_array(const char *str, char separator);
void split_str(const char *str, char separator,
char **result, char *content);
char *my_strdup(char *src);
int *my_intdup(int *src);
int my_str_isnum(char *str);

//game basic part

#endif
