/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main file
*/

#include "api_answer.h"
#include "macros.h"
#include "lib.h"
#include "loop.h"
#include <stdio.h>

int display_usage(UNUSED char const *s)
{
    printf("%s is supposed to be called from the pipes.sh script.\n", s);
    printf("Please download the latest source files and try again.\n");
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (display_usage(av[0]));
    create_logpath(LOGPATH);
    return (loop());
}
