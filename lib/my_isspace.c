/*
** EPITECH PROJECT, 2020
** my_isspace
** File description:
** check spaces in minishell1
*/

#include "include/my.h"

int my_isspace(char c)
{
    if (c == '\t' || c == '\n' || c == ' ')
        return (1);
    else
        return (0);
}
