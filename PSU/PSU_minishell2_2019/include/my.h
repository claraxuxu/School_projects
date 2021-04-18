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

#include "src.h"
#include "printf.h"

#ifndef _MY_H
#define _MY_H
#define MAX_SIZE 2000

typedef struct shell {
    int flag;
    char *redi_cmd;
}shell_t;

typedef struct mini {
    char input[2][256];
    int argc;
    int a;
    int i;
    int nbr;
    int len;
    int longest;
    char **cp_env;
    char **lenv;
    char *list[32];
}mini_t;

int check_input(mini_t *mini);
void print_prompt();
void find_in_env(mini_t *mini);
void in_cd(mini_t *mini);
void def_env(mini_t *mini, char **env);
int env_cmp(char *str1, char *str2, int len);

//main
void init_struct(mini_t *mini, shell_t *shell);
void def_list(char *ptr, mini_t *mini);
void cmd_list(char *ptr, mini_t *mini, char **env, shell_t *shell);
void other_cmd(mini_t *mini);
char *get_cmd_line(char *tmp);
void analyse_cmd(shell_t *shell, char *ptr);
void deal_flag(shell_t *shell);

#endif
