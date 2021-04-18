/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_str_tab.c
*/

#include <stdlib.h>

char my_strncpy(char *dest, char const *src, int n);

int is_alnum(char c)
{
    if ( c <= ' ' || c >= 127 )
        return (0);
    return (1);
}

int	len_w(char *str)
{
    int y = 0;
    int word = 0;

    while (str != NULL && str[y]) {
        if (is_alnum(str[y]) == 1 && is_alnum(str[y + 1]) == 0)
            word = word + 1;
        y = y + 1;
    }
    return (word);
}

char **my_str_tab(char *str)
{
    int	x = 0;
    int	y = 0;
    char **wordtab = malloc((len_w(str) + 1) * sizeof(char *));
    int	len = 0;

    while (str != NULL && str[y]) {
        if (is_alnum(str[y]))
            len = len + 1;
        if (is_alnum(str[y]) == 1 && is_alnum(str[y + 1]) == 0) {
            wordtab[x] = malloc(len + 1);
            wordtab[x][len] = '\0';
    	    my_strncpy(wordtab[x], &str[y - len + 1], len);
            len = 0;
            x = x + 1;
        }
        y = y + 1;
    }
    wordtab[x] = NULL;
    return (wordtab);
}