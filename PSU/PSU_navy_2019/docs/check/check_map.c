/*
** EPITECH PROJECT, 2019
** check_map
** File description:
** gestion d'erruer
*/

#include "my.h"


int check_map(char *buf)
{
    for (int i = 7; buf[i] != '\0'; i += 8) {
        if (buf[i] != '\n')
            return (-1);
    }
    if (buf[31] != '\0') return (-1);
    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == ':' && my_str_isalpha(buf[i + 1]) == 0)
            return (-1);
        if (buf[i] == ':' && my_str_isnum(buf[i - 1]) == 0)
            return (-1);
    }
}
