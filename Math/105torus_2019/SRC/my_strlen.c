/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** count number of string
*/

int my_strlen(char const *str)
{
    int a;

    for (a = 0; str[a]; a++);
    return (a);
}
