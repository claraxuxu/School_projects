/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** rebuild the ls command
*/

#include "include/my.h"

int main(int ac, char **av)
{
    if(ac == 1)
        do_ls(".",LS_NONE);
    else
        check(ac,av);
}
