/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** printf.h
*/

#include <stdarg.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <time.h>

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