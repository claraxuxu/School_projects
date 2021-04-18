/*
** EPITECH PROJECT, 2019
** print_prompt
** File description:
** mysh
*/

#include "../include/my.h"

void print_prompt(void)
{
    struct passwd *usrname;
    char buf[256];

    usrname = getpwuid(getuid());
    my_printf("\033[31m\033[1m[");
    my_printf("\033[33m");
    my_printf("my_shell: ");
    my_printf("\033[1m\033[34m%s", getcwd(buf,256));
    my_printf("\033[31m");
    my_printf(" $]:\033[39m\033[0m");
}
