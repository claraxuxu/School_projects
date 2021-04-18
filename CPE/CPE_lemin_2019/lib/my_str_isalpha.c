/*
** EPITECH PROJECT, 2019
** my_str_isaplha.c
** File description:
** task01
*/

int my_strlen(char *str);

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] >= '0' && str[i] <= 9 || str[i] >= 'a' && str[i] <= 'z' ||
        str[i] >= 'A' && str[i] <= 'Z')
        i++;
    if (str[i] == '\0')
        return (1);
    return (0);
}
