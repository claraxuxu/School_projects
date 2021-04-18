/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** split_str.c
*/

#include "tetris.h"

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
