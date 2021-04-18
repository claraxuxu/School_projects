/*
** EPITECH PROJECT, 2019
** help
** File description:
** for 103cipher help part
*/

#include "../include/my.h"

int help()
{
    printf("USAGE\n");
    printf("    ./103cipher message key flag\n\n");
    printf("DESCRIPTION\n");
    printf("    message\ta message, made of ASCII characters\n");
    printf("    key \tthe encryption key, made of ASCII characters\n");
    printf("    flage\t0 for the message to be encrypted, ");
    printf("1 to be decrypted\n");
}