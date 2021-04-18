/*
** EPITECH PROJECT, 2019
** 107transfer_2019
** File description:
** 107transfer.c
*/

#include "include/my.h"

int init(int ac, char **av, math_t *math)
{
    math->num = malloc(sizeof(char*) * math->ac);
    if (math->num == NULL)
        return (-1);
    for (int i = 0; i < math->ac; i++)
        math->num[i] = my_strdup(av[i + 1]);
    return (0);
}
int main(int ac, char **av)
{
    math_t math;
    math.ac = ac - 1;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        help_part();
    if (check_part(ac, av) == -1)
        return (84);
    if (init(ac, av, &math) == -1)
        return (84);
    progress(&math);
    return (0);
}