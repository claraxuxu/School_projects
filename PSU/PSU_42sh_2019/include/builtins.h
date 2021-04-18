/*
** EPITECH PROJECT, 2020
** builtins.h
** File description:
** builtins module header
*/

#ifndef BUILTINS_H
#define BUILTINS_H


#include "42sh.h"

typedef int(*builtin_t)(char **, int);

// builtin_where.c
int check_bltn_where(char **);
int built_in_where(char **, int);

// builtin_which.c
int check_bltn_which(char **);
int built_in_which(char **, int);

// builtin_exit.c
int built_in_exit(char **, int);

// builtin_env.c
int built_in_env(char **, int);

// builtin_cd.c
int built_in_cd(char **, int);
char **cd_error_handling(char **);
int change_dir(char **);
bool is_dir_accessible(char *);
bool is_directory(struct stat, char *);

// builtin_cd2.c
char **update_cd_argument(char **);
char *get_path(char *);
char **update_pwd_values(char **, char *, char *);

// builtin_setenv.c
int built_in_setenv(char **, int);
int setenv_check_input(char **, int);
char **set_to_env(char **, char *);

// builtin_setenv2.c
bool check_if_alphanum(char);

// builtin_unsetenv.c
int built_in_unsetenv(char **, int);
char **reset_from_position(int, char **);
int unsetenv_check_input(char **);

// get_prompt.c
int built_in_prompt(char **, int);
char *get_prompt(char **);
char *prompt_switch_case(char, char **);
char *prompt_cwd(char **);

// prompt_git.c
char *prompt_git(char *);
char *close_and_free(DIR *, char *);
char *go_to_last_dir(char *);
char *prompt_git_found_dir(char *);

// builtin_echo.c
int built_in_echo(char **input, int rvalue);

// get_function_pointer.c
builtin_t get_builtin(char *input);

#endif /* BUILITINS */
