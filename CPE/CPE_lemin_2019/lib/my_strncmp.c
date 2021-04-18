/*
** EPITECH PROJECT, 2019
** my_strncmp.c
** File description:
** task06
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; s1[i] == s2[i]; i++)
        if (i == n)
            return (1);
    return (0);
}
