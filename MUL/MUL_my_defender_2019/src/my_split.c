/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** my_split.c
*/

#include "defender.h"

char **my_strsplit(char *str, char c)
{
    int last_match = -1;
    int count = 0;
    char **result;
    char *new_str = my_strdup(str);

    for (int i = 0; new_str[i]; i++)
        if (new_str[i] == c) count++;
    result = malloc(sizeof(char *) * (count + 2));
    count = 0;
    for (int i = 0; new_str[i]; i++) {
        if (new_str[i] == c) {
            new_str[i] = '\0';
            result[count] = new_str + last_match + 1;
            last_match = i;
            count++;
        }
    }
    result[count] = new_str + last_match + 1;
    result[count + 1] = 0;
    return result;
}

void free_split(char **split)
{
    free(split[0]);
    free(split);
}