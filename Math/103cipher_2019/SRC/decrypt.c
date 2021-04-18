/*
** EPITECH PROJECT, 2019
** decrypt
** File description:
** for 103cipher decrypt part
*/

#include "../include/my.h"

int get_len_msg(decry_t key, char *av)
{
    int len = 0;

    for (int i = 0; av[i] != '\0'; i++)
        if (av[i] == ' ' && av[i + 1] != ' ')
            len++;
    if (len % key.len_mat != 0)
        len++;
    return (len);
}

int decrypt(char **av)
{
    decry_t key;

    key.key_len = my_strlen(av[2]);
    key.len_mat = len(av[2]);
    key.len_msg = get_len_msg(key,av[1]);
    key.code = malloc(sizeof(int*) * key.len_msg + 1);
    get_code(&key,av[1]);
    get_matrix(&key,av[2]);
    get_result_mat(&key);
    get_sentence(&key,av[1]);
}
