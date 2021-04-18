/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** task03
*/

int my_strlen(char const *str)
{
    int cont = 0;

    if (str[0] == '\0')
        return (0);
    while (str[cont] != '\0') {
        cont++;
    }
    return (cont);
}
