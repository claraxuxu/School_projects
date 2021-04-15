/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** src.h
*/


int my_printf(char *format,...);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *res, char *line, int len);
int my_put_nbr(int nb);

void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char *str1, char *str2);
int my_strncmp(char *str1, char *str2, int len);
char *my_strcat(char *str, char *str2);
char *my_strdup(char *src);
int my_isspace(char c);