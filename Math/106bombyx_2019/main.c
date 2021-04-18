/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** count number of string
*/

#include "include/my.h"

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] != '-' && av[1][1] != 'h')
        return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        help();
    if (ac != 3 && ac != 4)
        return (84);
    if (ac == 3)
        first_check(av);
    if (ac == 4) 
        second_check(av);
    return (0);
}