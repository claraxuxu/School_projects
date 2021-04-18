/*
** EPITECH PROJECT, 2019
** help
** File description:
** help part for sokoban
*/

#include "../include/my.h"

void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map, containing");
    my_putstr(" '#' for walls, \n");
    my_putstr("          'P' for the player, 'X' for voxes and 'O'");
    my_putstr(" for storage locations.\n");
}
