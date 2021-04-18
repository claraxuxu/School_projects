/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** task01
*/

char *my_strcpy(char *dest, char const *src)
{
    int c = 0;
    while (src[c] != '\0') {
        dest[c] = src[c];
        c++;
    }
    while (dest[c] != '\0') {
        dest[c] = '\0';
        c++;
    }
    return (dest);
}
