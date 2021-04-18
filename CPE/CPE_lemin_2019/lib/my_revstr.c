/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** task03
*/

char *my_revstr(char *str)
{
    int n = 0;
    while (str[n] != '\0')
        n++;
    n--;
    int i = 0;
    while ((n != i) && (n > i)) {
        int c = str[n];
        str[n] = str[i];
        str[i] = c;
        i++;
        n--;
    }
    return (str);
}
