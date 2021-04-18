/*
** EPITECH PROJECT, 2020
** my_itoa
** File description:
** turns int to char
*/

#include "../include/my.h"

void my_itoa(int n, char s[])
{
    int i = 0;
    int sign = n;
    char temp;

    if (sign < 0)
        n = -n;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    for (int j = 0; j <= i / 2; j++) {
        temp = s[j];
        s[j] = s[i - 1 - j];
        s[i - 1 - j] = temp;
    }
}
