/*
** EPITECH PROJECT, 2019
** cipher_16
** File description:
** for 103cipher 0_16 part
*/

#include "../include/my.h"

void long16(char **av, keyci_t *key, int len_ms)
{
    for (int i = 0, j = 1, k = 2, g = 3; i < len_ms; 
         i += 4, j += 4, k += 4, g += 4) {
        key->en[g - 3] = av[1][i] * key->key[0];
        key->en[g - 3] +=  av[1][j] * key->key[4];
        key->en[g - 3] +=  av[1][k] * key->key[8];
        key->en[g - 3] +=  av[1][g] * key->key[12];
        key->en[g - 2] =  av[1][i] * key->key[1];
        key->en[g - 2] +=  av[1][j] * key->key[5];
        key->en[g - 2] +=  av[1][k] * key->key[9];
        key->en[g - 2] +=  av[1][g] * key->key[13];
        key->en[g - 1] =  av[1][i] * key->key[2];
        key->en[g - 1] +=  av[1][j] * key->key[6];
        key->en[g - 1] +=  av[1][k] * key->key[10];
        key->en[g - 1] +=  av[1][g] * key->key[14];
        key->en[g] =  av[1][i] * key->key[3];
        key->en[g] +=  av[1][j] * key->key[7];
        key->en[g] +=  av[1][k] * key->key[11];
        key->en[g] +=  av[1][g] * key->key[15];
    }
}
int cipher_16(char **av, keyci_t *key)
{
    int len_ms = my_strlen(av[1]);
    key->en = malloc(sizeof(int) * len_ms + 4);

    long16(av,key,len_ms);
    for (int i = 0; i < len_ms; i++) {
        printf("%i",key->en[i]);
        if (i < len_ms - 1)
            printf(" ");
    }
}
