/*
** EPITECH PROJECT, 2019
** get_sentence
** File description:
** for 103cipher decrypt part answer of sentence
*/

#include "../include/my.h"

int get_sentence_4(decry_t *key, char *av)
{
    for (int i = 0, j = 1; i < key->len_msg; i += 2, j += 2) {
        key->answer[j - 1] = round((key->code[i] * key->mat[0]) +
                                   (key->code[j] * key->mat[2]));
        key->answer[j] = round((key->code[i] * key->mat[1]) +
                               (key->code[j] * key->mat[3]));
    }
}
int get_sentence_9(decry_t *key, char *av)
{
    for (int i = 0, j = 1, k = 2; i < key->len_msg; i += 3, j += 3, k += 3) {
        key->answer[k - 2] = round((key->code[i] * key->mat[0]) + 
                                   (key->code[j] * key->mat[3]) +
                                   (key->code[k] * key->mat[6]));
        key->answer[k - 1] = round((key->code[i] * key->mat[1]) + 
                                   (key->code[j] * key->mat[4]) +
                                   (key->code[k] * key->mat[7]));
        key->answer[k] = round((key->code[i] * key->mat[2]) + 
                               (key->code[j] * key->mat[5]) +
                               (key->code[k] * key->mat[8]));
    }
}
int get_sentence(decry_t *key, char *av)
{
    key->answer = malloc(sizeof(int*) * key->len_msg);

    if (key->len_mat == 4)
        get_sentence_4(key,av);
    else if (key->len_mat == 9)
        get_sentence_9(key,av);
    printf("Decrypted message:\n");
    for (int i = 0; i < key->len_msg - 1; i++) 
        printf("%c",key->answer[i]);
    printf("\n");
}
