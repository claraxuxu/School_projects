/*
** EPITECH PROJECT, 2019
** my_str_isprintable.c
** File description:
** task01
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        if (str[i] < 32)
            return (0);
    return (1);
}
