/*
** EPITECH PROJECT, 2019
** cipher_4
** File description:
** for 103cipher 0_4 part
*/

#include "../include/my.h"

int cipher_1(char **av, keyci_t *key)
{
    int len_ms = my_strlen(av[1]);
    key->en = malloc(sizeof(int) * len_ms + 1);

    for (int i = 0; i < len_ms; i++)
        key->en[i] = av[1][i] * key->key[0];
    for (int i = 0; i < len_ms; i++) {
        printf("%d",key->en[i]);
        if (i < len_ms - 1)
            printf(" ");
    }
}
int cipher_4(char **av, keyci_t *key)
{
    int len_ms = my_strlen(av[1]);
    key->en = malloc(sizeof(int) * len_ms + 3);

    for (int i = 0, j = 1; i <= len_ms; i += 2, j += 2) {
        key->en[j - 1] = av[1][i] * key->key[0];
        key->en[j - 1] +=  av[1][j] * key->key[2];
        key->en[j] =  av[1][i] * key->key[1];
        key->en[j] +=  av[1][j] * key->key[3];
    }
    for (int i = 0; i <= len_ms; i++) {
        printf("%i",key->en[i]);
        if (i <= len_ms - 1)
            printf(" ");
    }
}
