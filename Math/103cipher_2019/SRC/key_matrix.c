/*
** EPITECH PROJECT, 2019
** key_matrix
** File description:
** for 103cipher encrypt part
*/

#include "../include/my.h"

int encrypt(char **av, keyci_t *key)
{
    int len_ms = my_strlen(av[1]);
    int size = pow(key->len_mat,0.5);

    printf("\nEncrypted message:\n");
    if (key->len_mat == 1)
        cipher_1(av,key);
    if (size == 2)
        cipher_4(av,key);
    else if (size == 3)
        cipher_9(av,key);
    else if (size == 4)
        cipher_16(av,key);
    printf("\n");
}
int answer_key(keyci_t key)
{   
    int k = pow(key.len_mat,0.5);

    if (key.key_len == 1)
        printf("%d\n",key.key[0]);
    if (key.len_mat == 4)
        for (int i = 0; i < key.len_mat; i += k)
            printf("%d\t%d\n",key.key[i],key.key[i + 1]);
    if (key.len_mat == 9)
        for (int i = 0; i < key.len_mat; i += k)
            printf("%d\t%d\t%d\n",key.key[i],key.key[i + 1],key.key[i + 2]);
    if (key.len_mat == 16)
        for (int i = 0; i < key.len_mat; i += k)
            printf("%d\t%d\t%d\t%d\n",key.key[i],key.key[i + 1],
                   key.key[i + 2],key.key[i + 3]);
}
int key_matrix(char **av)
{
    keyci_t key;
    int dif;
    key.key_len = my_strlen(av[2]);
    key.len_mat = len(av[2]);
    key.key = malloc(sizeof(int) * key.len_mat);

    for (int i = 0; i < key.key_len; i++)
        key.key[i] = (int)av[2][i];
    if (key.key_len < key.len_mat)
        dif = key.len_mat - key.key_len;
    printf("Key matrix:\n");
    answer_key(key);
    encrypt(av,&key);
}
