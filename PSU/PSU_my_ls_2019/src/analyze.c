/*
** EPITECH PROJECT, 2019
** analyze
** File description:
** for myls
*/

#include "../include/my.h"

int analyze(char *input)
{
    if ((my_strlen(input)) == 2)
        switch (input[1]) {
        case 'l':
            return (LS_L);
        case 'd':
            return (LS_D);
        case 'R':
            return (LS_R);
        }
    else if ((my_strlen(input)) == 3)
        if (input[1] == 'l' && input[2] == 'R')
            return (LS_RL);
    return (-1);
}
