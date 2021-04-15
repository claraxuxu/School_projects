/*
** EPITECH PROJECT, 2019
** print_prompt
** File description:
** mysh
*/

#include "include/my.h"

void print_prompt(void)
{
    char buf[256];

    my_printf("\033[31m");
    my_printf("[");
    my_printf("\033[33m");
    my_printf("my_shell:%s",getcwd(buf, 256));
    my_printf("\033[31m");
    my_printf("$]:");
    my_printf("\033[39m");
}
