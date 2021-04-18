/*
** EPITECH PROJECT, 2019
** cipher_16
** File description:
** for 103cipher 0_16 part
*/

#include "../include/my.h"

int isnum(char av)
{
    int test = 0;

    if ((av >= '0' && av <= '9') ||
        (av == '-' && av >= '0' && av <= '9'))
        test++;
    return (test);
}
