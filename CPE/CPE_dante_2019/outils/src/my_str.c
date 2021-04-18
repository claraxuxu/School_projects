/*
** EPITECH PROJECT, 2019
** my_str
** File description:
** my_str_to_word_array/cat/cmp/cpy
*/

#include "../include/my.h"

char **my_str_to_word_array(const char *str, char separator)
{
    char **result = malloc(sizeof(char *) * my_strlen(str));
    char *content = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (result == NULL || content == NULL || my_strlen(str) == 0)
        return (NULL);
    content[0] = '\0';
    split_str(str, separator, result, content);
    return (result);
}

char *my_strcat(char *dest, const char *src)
{
    int dest_len = my_strlen(dest);
    int j = 0;

    for (j = 0; src[j] != '\0'; j++)
        dest[dest_len + j] = src[j];
    dest[dest_len + j] = '\0';
    return (dest);
}

int my_strcmp(char *str1, char *str2)
{
    for (; *str1 != '\0'; str1++, str2++) {
        if (*str1 != *str2) {
            if (*str1 > *str2)
                return (1);
            else if (*str1 < *str2)
                return (-1);
        }
    }
    if (*str1 == '\0' || *str2 == '\0') {
        if (*str1 > *str2)
            return (1);
        else if (*str1 < *str2)
            return (-1);
        return (0);
    }
    return (0);
}

char *my_strcpy(char *dest, char const *src)
{
    int count = 0;
    char const *cpy = src;

    for (cpy = src; *cpy != '\0'; cpy++)
        count ++;
    for (int j = 0; j <= count; j++)
        dest[j] = src[j];
    return (dest);
}

void my_strncpy(char *res, char *line, int len)
{
    int i = 0;

    if (line == NULL)
        res[0] = '\0';
    else {
        for (; i < len; i++)
            res[i] = line[i];
        res[i] = '\0';
    }
}
