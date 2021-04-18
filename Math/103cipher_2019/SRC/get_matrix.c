/*
** EPITECH PROJECT, 2019
** get_matrix
** File description:
** for 103cipher decrypt part
*/

#include "../include/my.h"

float rev_4(decry_t *key)
{
    key->rev = (key->key[0] * key->key[3]) -
	(key->key[2] * key->key[1]);
}
float rev_9(decry_t *key)
{
    key->rev = key->key[0] * (key->key[4] * key->key[8] -
                              key->key[5] * key->key[7]) -
        key->key[3] * (key->key[1] * key->key[8] - key->key[2]
                         * key->key[7]) + key->key[6] *
        (key->key[1] * key->key[5] - key->key[2] * key->key[4]);
}
float get_rev(decry_t *key)
{
    if (key->len_mat == 4)
        rev_4(key);
    else if (key->len_mat == 9)
        rev_9(key);
}
int get_matrix(decry_t *key, char *av)
{
    int dif = 0;
    key->key = malloc(sizeof(int*) * key->len_mat);

    for (int i = 0; i <= key->key_len; i++)
        key->key[i] = (int)av[i];
    if (key->key_len < key->len_mat)
        dif = key->len_mat - key->key_len;
    for (int i = 1; i <= dif; i++)
        key->key[key->key_len + i] = 0;
    get_rev(key);
}
