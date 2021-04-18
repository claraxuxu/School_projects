/*
** EPITECH PROJECT, 2019
** struct
** File description:
** my_ls
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#define LS_NONE 0
#define LS_L 101
#define LS_R 102
#define LS_D 103
#define LS_RL (LS_R + LS_L)
#ifndef MY_H_
#define MY_H_
typedef struct dols {
    char dirs[20][100];
    int dir_count;
    char complete_d_name[200];
    int mode;
}dols_t;
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
void my_putchar(char c);
void my_putstr(char const *str);
char *my_strcat(char *dest, char const *src);
char *gid_to_name (gid_t gid);
char *uid_to_name (uid_t uid);
void mode_to_letters_two(int mode, char *str);
void mode_to_letters(int mode, char *str);
int analyze (char *input);
void show_file_info (char* filename, struct stat *info_p);
int check (int ac, char **av);
void do_ls(char *dirname, int mode);
void do_ls_two(char *dirname, int mode);
void do_ls_three(dols_t *ls, char *dirname, struct dirent *p);
void my_itoa(int n, char s[]);

void my_put_usnbr(long nb);
unsigned long my_pow(int a, int b);
void get_octal(int num);
void get_float(double f);
void situ_x(va_list arg);
void situ_x_mas(va_list arg);
void res_dif_int(int num, int base);
void get_binary(int num);
void get_hex(int num);
void get_float(double f);
void situ_gene(char *begin, va_list arg);
void situ_special(char *begin, va_list arg);
#endif
