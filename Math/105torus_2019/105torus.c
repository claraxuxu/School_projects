/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** math
*/

#include "include/my.h"

int dif_opt(num_t *num)
{
    if (num->opt == 1)
        disec_metho(num);
    if (num->opt == 2)
        newton_metho(num);
    if (num->opt == 3)
        secant_metho(num);
}
int check(int ac, char **av)
{
    num_t num;
    change_to_num(&num,av);
    if (ac != 8 || num.opt > 3 || num.opt < 1 || num.n <= 0)
        exit(84);
    for (int i = 1; i < ac; i++)
        if ((my_str_isnum(av[i])) == 0)
            exit (84);
    dif_opt(&num);
}
int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        help();
    else if (ac != 8)
        exit (84);
    else
        check(ac, av);
    return (0);
}
