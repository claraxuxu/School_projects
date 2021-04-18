/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** task06
*/

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] == s2[i]; i++)
        if (s1[i] == '\0' && s2[i] == '\0')
            return (1);
    return (0);
}
