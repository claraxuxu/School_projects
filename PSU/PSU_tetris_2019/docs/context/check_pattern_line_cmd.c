/*
** EPITECH PROJECT, 2020
** check_pattern_line_cmd
** File description:
** function that check the pattern of arguments
*/

#include "tetris.h"

bool check_unexpected_argument(int argc)
{
    return argc != optind ? true : false;
}