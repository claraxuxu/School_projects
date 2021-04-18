/*
** EPITECH PROJECT, 2019
** my_compute_square_root.c
** File description:
** task05
*/

int my_compute_square_root(int nb)
{
    int test = 1;

    if (nb <= 0)
        return (0);
    while (test * test != nb) {
        test++;
        if (nb == test * test)
            return (test);
        if (test == nb)
            return (0);
    }
}
