/*
** EPITECH PROJECT, 2019
** main
** File description:
** main file for solver dante
*/

#include "include/sol.h"

int main(int ac, char **av)
{
    sol_t sol;
    if (check(&sol, ac, av) == -1)
        return (84);
    if (init(&sol) == -1)
        return (84);
    return (0);
}
