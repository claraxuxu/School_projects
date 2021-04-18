/*
** EPITECH PROJECT, 2019
** printf
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

unsigned long my_pow(int a, int b);
void get_octal(int num);
void get_float(double f);
void res_dif_int(int num, int base);
void get_binary(int num);
void get_float(double f);
void situ_gene(char *begin, va_list arg);