/*
** EPITECH PROJECT, 2019
** my_find_prime_sup.c
** File description:
** task07
*/

int exs(int nb)
{
    if (nb < 0)
        return (2);
    if ((nb >= 0) && (nb < 3))
        return (2);
}

int bdm(int boucledelamort, int nb, int test)
{
    while (boucledelamort == 1) {
        test--;
        if (nb % test == 0) {
            nb++;
            test = nb - 1;
        }
        if (test == 2)
            return (nb);
    }
}

int my_find_prime_sup(int nb)
{
    int test;
    int boucledelamort = 1;

    test = nb - 1;
    if (nb < 3)
        exs(nb);
    else if (nb == 3)
        return (3);
    else
        bdm(boucledelamort, nb, test);
}
