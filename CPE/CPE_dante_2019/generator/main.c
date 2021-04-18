/*
** EPITECH PROJECT, 2019
** main
** File description:
** main file for genrator dante
*/

#include "../include/gene.h"

int check_two(char **av)
{
    if (my_str_isnum(av[1]) == 0 || my_str_isnum(av[2]) == 0)
        return (-1);
    if (my_atoi(av[1]) <= 2 || my_atoi(av[2]) <= 2)
        return (-1);
    if (my_atoi(av[1]) * my_atoi(av[2]) <= 0)
        return (-1);
    return (0);
}

int check(int ac, char **av)
{
    if (ac < 3 || ac > 4)
        return (-1);
    if (ac == 4 && (my_strcmp(av[3], "imperfect") != 0) &&
        (my_strcmp(av[3], "perfect") != 0))
        return (-1);
    if (check_two(av) == -1)
        return (-1);
    return (0);
}

void progress(gene_t *gene)
{
    if (gene->perfect == 1)
        pro_perfect(gene);
    else
        pro_imperfect(gene);
    output_map(gene);
}

int main(int ac, char **av)
{
    gene_t gene;
    srand(time(NULL));
    if (check(ac, av) == -1)
        return (84);
    init(&gene, ac, av);
    progress(&gene);
    return (0);
}
