/*
** EPITECH PROJECT, 2019
** 103cipher
** File description:
** 
*/

#include "include/my.h"
#include <string.h>

int main(int ac, char **av)
{
    if (ac < 2 || ac > 4)
        exit (84);
    else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        help();
    else if (check_alpha(av[1]) == 0 && ac == 4 && av[3][0] == '0' && 
             my_strlen(av[2]) > 0)
        key_matrix(av);
    else if (check_num(av[1]) == 0 && ac == 4 && av[3][0] == '1' && 
             my_strlen(av[2]) > 0)
        decrypt(av);
    else
        exit (84);
    return (0);
}
