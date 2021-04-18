/*
** EPITECH PROJECT, 2020
** concat
** File description:
** function that concatenates two strings.
*/

#include "tetris.h"

char *sub_concat(char *s1, char *s2)
{
    int size_malloc = my_strlen(s1) + my_strlen(s2);
    char *dest = malloc(sizeof(char) * (size_malloc + 1));
    int i = 0;

    for (int j = 0; s1[j] != 0; j++, i++)
        dest[i] = s1[j];
    for (int j = 0; s2[j] != 0; j++, i++)
        dest[i] = s2[j];
    dest[i] = 0;
    return dest;
}

char *concat(char *s1, char *s2)
{
    if (s1 == NULL)
        return my_strdup(s2);
    if (s2 == NULL)
        return my_strdup(s1);
    return sub_concat(s1, s2);
}
