/*
** EPITECH PROJECT, 2019
** cipher_9
** File description:
** for 103cipher 0_9 part
*/

#include "../include/my.h"

int put_answer9(int len_ms, keyci_t *key)
{
    for (int i = 0; i <= len_ms; i++) {
        printf("%i",key->en[i]);
        if (i <= len_ms - 1)
            printf(" ");
    }
}
int cipher_9(char **av, keyci_t *key)
{
    int len_ms = my_strlen(av[1]);
    key->en = malloc(sizeof(int) * len_ms);

    for (int i = 0, j = 1, k = 2; i < len_ms; i += 3, j += 3, k += 3) {
        if (av[1][j] == '\0') {
            av[1][j] = 0;
            av[1][k] = 0;
        }
        key->en[k - 2] = (av[1][i] * key->key[0]);
        key->en[k - 2] += (av[1][j] * key->key[3]);
        key->en[k - 2] += (av[1][k] * key->key[6]);
        key->en[k - 1] = (av[1][i] * key->key[1]);
        key->en[k - 1] += (av[1][j] * key->key[4]);
        key->en[k - 1] += (av[1][k] * key->key[7]);
        key->en[k] = (av[1][i] * key->key[2]);
        key->en[k] += (av[1][j] * key->key[5]);
        key->en[k] += (av[1][k] * key->key[8]);
    }
    put_answer9(len_ms,key);
}