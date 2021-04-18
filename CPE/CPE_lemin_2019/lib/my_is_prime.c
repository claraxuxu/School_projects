/*
** EPITECH PROJECT, 2019
** my_is_prime.c_
** File description:
** task06
*/

int my_is_prime(int nb)
{
    int test;

    test = nb - 1;
    if ((nb == 2) || (nb == 3))
        return (1);
    if ((nb <= 1) || (nb == 4))
        return (0);
    while (nb % test != 0) {
        test--;
        if (test == 2)
            return (1);
    }
    return (0);
}
