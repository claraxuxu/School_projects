/*
** EPITECH PROJECT, 2019
** crand
** File description:
** choose a number randomly
*/

#include "../include/my.h"

int crand(int a, int b)
{
    return (random() % b + a);
}
