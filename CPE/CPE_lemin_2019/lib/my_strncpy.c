/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** task02
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int c = 0;
    while (c < n) {
        dest[c] = src[c];
        c++;
    }
    return (dest);
}
