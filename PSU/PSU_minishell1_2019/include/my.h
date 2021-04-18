/*
** EPITECH PROJECT, 2019
** struct
** File description:
** mysh
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <time.h>
#ifndef _MY_H
#define _MY_H
#define MAX_SIZE 2000

typedef struct mini {
	char input[2][256];
	int argc;
	int a;
	int nbr;
	int len;
	int longest;
	char **cp_env;
	char **lenv;
	char *list[32];
}mini_t;

void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char *str1, char *str2);
char *my_strcat(char *str, char *str2);
int my_isspace(char c);
void get_setenv(mini_t *mini);
void get_unsetenv(mini_t *mini);
int check_input(mini_t *mini);
void print_prompt();
char find_in_env(mini_t *mini);
void in_cd(mini_t *mini);
void def_env(mini_t *mini, char **env);
int env_cmp(char *str1, char *str2, int len);

int my_printf(char *format,...);
char *my_strcpy(char *dest, char const *src);
int my_put_nbr(int nb);
unsigned long my_pow(int a, int b);
void get_octal(int num);
void get_float(double f);
void situ_x(va_list arg);
void situ_x_mas(va_list arg);
void res_dif_int(int num, int base);
void get_binary(int num);
void get_float(double f);

void situ_gene(char *begin, va_list arg);
void situ_special(char *begin, va_list arg);
#endif
