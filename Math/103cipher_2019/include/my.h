/*
** EPITECH PROJECT, 2019
** header file
** File description:
** prototypes of all the functions in lib
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef MY_H_
#define MY_H_

typedef struct encry{
    int key_len;
    int len_mat;
    int *key;
    int *en;
}keyci_t;

typedef struct decry{
    int key_len;
    int len_mat;
    int len_msg;
    int *code;
    int *key;
    int *answer;
    float rev;
    float *mat;
}decry_t;

#endif
int my_strlen(char const *str);
int isnum(char av);
int help();
int len(char *av);

int key_matrix(char **av);
int cipher_1(char **av, keyci_t *key);
int cipher_9(char **av, keyci_t *key);
int put_answer9(int len_ms, keyci_t *key);
int cipher_4(char **av, keyci_t *key);
int cipher_16(char **av, keyci_t *key);

int decrypt(char **av);
int check_alpha(char *av);
int check_num(char *av);
int get_matrix(decry_t *key, char *av);
int get_code(decry_t *key, char *av);
int get_sentence(decry_t *key, char *av);
float get_result_mat(decry_t *key);
