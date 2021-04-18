/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** 
*/

#include "include/my.h"

int isnum(int ac, char **av)
{
    int test = 0;

    for (int i = 1; i<= (ac - 1); i++) {
        if ((av[i][0] >= '0' && av[i][0] <= '9') ||
            (av[i][0] == '-' && av[i][1] >= '0' && av[i][1] <= '9'))
                test++;
        }
    return (test);
}

void situ_main(char **av)
{
    if (av[3][1] == 't')
        translation(av);
    else if (av[3][1] == 'z')
        scaling(av);
}
void situ_main2(char **av)
{
    if (av[3][1] == 'r')
        rotation(av);
    else if (av[3][1] == 's')
        reflection(av);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        help();
    else if (ac == 6 && av[3][0] == '-' && isnum(ac,av) == 4)
        situ_main(av);
    else if (ac == 5 && av[3][0] == '-' && isnum(ac,av) == 3)
        situ_main2(av);
    else
        return (84);
    return (0);
}