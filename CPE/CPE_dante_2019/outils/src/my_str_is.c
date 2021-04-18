/*
** EPITECH PROJECT, 2019
** my_str_is
** File description:
** my_str_is num/alpha
*/

#include "../include/my.h"

int my_str_isnum(char *str)
{
    int nbr = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 48 && str[i] <= 57)
            nbr++;
    if (nbr == my_strlen(str))
        return (1);
    return (0);
}

int my_str_isalpha(char str)
{
    int alpha = 0;

    if (str >= 65 && str <= 90)
            alpha++;
    return (alpha);
}


void split_str(const char *str, char separator,
char **result, char *content)
{
    int word_len = 0;
    int total_len = 0;

    for (int i = 0; i < my_strlen(str) + 1; i++) {
        if (str[i] != separator) {
            content[word_len] = str[i];
            word_len++;
            content[word_len] = '\0';
        } else if (my_strlen(content) > 0) {
            word_len = 0;
            result[total_len] = my_strdup(content);
            total_len++;
        }
    }
    if (my_strlen(content) > 0) {
        content[word_len] = '\0';
        result[total_len] = my_strdup(content);
        total_len++;
    }
    result[total_len] = '\0';
}