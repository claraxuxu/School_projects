/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** manage_params.c
*/

#include "tetris.h"

int get_nb_optarg(char *optarg, char *binary_name)
{
    char *arg = my_strdup(optarg);
    int i = 0;

    if (arg[0] == '=')
        i++;
    if (arg[i] == '{')
        i++;
    if (arg[my_strlen(arg) - 1] == ',' || arg[my_strlen(arg) - 1] == '}') {
        arg = my_strnuntil_cpy(&arg[i], my_strlen(&arg[i]) - 1);
        i = 0;
    }
    if (arg != NULL && my_str_isnum(&arg[i]) == 1)
        return my_getnbr(&arg[i]);
    help_part(binary_name);
}

int get_optarg(char *optarg, char *binary_name)
{
    char *arg = my_strdup(optarg);
    int i = 0;

    if (arg[0] == '=')
        i++;
    if (arg[i] == '{')
        i++;
    if (arg[my_strlen(arg) - 1] == '}') {
        arg = my_strnuntil_cpy(&arg[i], my_strlen(&arg[i]) - 1);
        i = 0;
    }
    if (arg != NULL && my_strlen(&arg[i]) == 1)
        return (arg[i]);
    if (arg != NULL && my_strcmp(&arg[i], " ") == 0)
        return (arg[i]);
    else help_part(binary_name);
}
