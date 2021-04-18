/*
** EPITECH PROJECT, 2019
** get_code
** File description:
** for 103cipher decrypted part
*/

#include "../include/my.h"

int get_code(decry_t *key, char *av)
{
    int j = 0;
    int nbr = 0;

    for (int i = 0; av[i]; i++) {
        if (av[i] >= '0' && av[i] <= '9') {
            nbr *= 10;
            nbr += av[i] - '0';
        }
        else if (nbr > 0) {
            key->code[j] = nbr;
            nbr = 0;
            j++;
        }
    }
    if (nbr != 0)
        key->code[j] = nbr;
}