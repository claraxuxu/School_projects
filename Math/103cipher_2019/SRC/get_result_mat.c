/*
** EPITECH PROJECT, 2019
** get_result_mat
** File description:
** for 103cipher decrypt part
*/

#include "../include/my.h"

int put_answer(decry_t *key)
{
    int p = pow(key->len_mat,0.5);

    printf("Key matrix:\n");
    for (int i = 0; i < key->len_mat; i += p) {
        if (key->mat[i] == 0)
			printf("%s\t", "0.0");    
        else 
            printf("%.3f\t",key->mat[i]);
        if (key->mat[i + 1] == 0)
			printf("%s\t", "0.0");    
        else 
            printf("%.3f\t",key->mat[i + 1]);
        if (key->mat[i + 2] == 0)
			printf("%s\n", "0.0");    
        else
            printf("%.3f\n",key->mat[i + 2]);
    }
}
float get_result_mat_4(decry_t *key)
{
    int p = pow(key->len_mat,0.5);

    key->mat[0] = key->key[3] / key->rev;
    key->mat[1] = - (key->key[1]) / key->rev;
    key->mat[2] = - (key->key[2]) / key->rev;
    key->mat[3] = key->key[0] / key->rev;
    printf("Key matrix:\n");
    for (int i = 0; i < key->len_mat; i += p)
        printf("%.3f\t%.3f\n",key->mat[i],key->mat[i + 1]);
}
float get_result_mat_9(decry_t *key)
{
    key->mat[0] = (key->key[4] * key->key[8]
                   - key->key[5] * key->key[7]) / key->rev;
    key->mat[1] = - (key->key[1] * key->key[8]
                     - key->key[2] * key->key[7]) / key->rev;
    key->mat[2] = (key->key[1] * key->key[5]
                   - key->key[2] * key->key[4]) / key->rev;
    key->mat[3] = - (key->key[3] * key->key[8]
                     - key->key[5] * key->key[6]) / key->rev;
    key->mat[4] = (key->key[0] * key->key[8]
                   - key->key[2] * key->key[6]) / key->rev;
    key->mat[5] = - (key->key[0] * key->key[5]
                     - key->key[2] * key->key[3]) / key->rev;
    key->mat[6] = (key->key[3] * key->key[7]
                   - key->key[4] * key->key[6]) / key->rev;
    key->mat[7] = - (key->key[0] * key->key[7]
                     - key->key[1] * key->key[6]) / key->rev;
    key->mat[8] = (key->key[0] * key->key[4]
                   - key->key[1] * key->key[3]) / key->rev;
}
float get_result_mat(decry_t *key)
{
    key->mat = malloc(sizeof(float*) * key->len_mat);

    if (key->len_mat == 4)
        get_result_mat_4(key);
    else if (key->len_mat == 9) {
        get_result_mat_9(key);
        put_answer(key);
    }
    printf("\n");
}
