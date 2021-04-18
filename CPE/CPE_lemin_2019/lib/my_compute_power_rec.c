/*
** EPITECH PROJECT, 2019
** my_compute_power_rec.c
** File description:
** task04
*/

int my_compute_power_rec(int nb, int p)
{
    int bb;
    int pow = nb;

    if (p < 0)
        return (0);
    else if (p == 0)
        return (1);
    else {
        bb = my_compute_power_rec(nb, p - 1) * pow;
        return (bb);
    }
}
