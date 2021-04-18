/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick game wth AI
*/

#include "include/my.h"

int main(int ac, char **av)
{
    map_t game;
    int a = 0;
    int b = 0;

    if (ac != 3)
        return (84);
    a = my_strlen(av[1]);
    b = my_strlen(av[2]);
    if (my_str_isnum(av[1]) != a || my_str_isnum(av[2]) != b)
        return (84);
    game.size = my_getnbr(av[1]);
    game.nbr = my_getnbr(av[2]);
    game.exit = 1;
    if (game.size < 1 || game.size > 100 || game.nbr <= 0)
        return (84);
    else
        map(&game);
    return (game.exit);
}
