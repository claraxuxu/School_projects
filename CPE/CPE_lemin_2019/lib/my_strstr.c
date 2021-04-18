/*
** EPITECH PROJECT, 2019
** my_strstr.c
** File description:
** task05
*/

int my_strstr(char *str, char const *to_find)
{
    int n = 0;
    int i = 0;
    char ibase = 0;
    int nbase = n;

    while (str[ibase] != '\0') {
        i = ibase;
        while (str[i] == to_find[n]) {
            n++;
            i++;
            if (to_find[n] == '\0'){
                return (1);
            }
        }
        n = 0;
        ibase++;
    }
    return (0);
}
