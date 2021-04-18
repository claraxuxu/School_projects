/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** help.c
*/

#include "tetris.h"

void help_part(char *binary_name)
{
    my_printf("Usage:\t%s [options]\nOptions:\n", binary_name);
    my_printf("  --help\t       Display this help\n");
    my_printf("  -L --level={num}     Start Tetris at level num (def: 1)\n");
    my_printf("  -l --key-left={K}    Move the tetrimino LEFT using the ");
    my_printf("K key (def: left arrow)\n  -r --key-right={K}   Move the ");
    my_printf("tetrimino RIGHT using the K key (def: right arrow)\n  -t");
    my_printf(" --key-turn={K}    TURN the tetrimino clockwise 90d using the");
    my_printf(" K key (def: top arrows)\n  -d --key-drop={K}    DROP the tet");
    my_printf("rimino using the K key (def: down arrow)\n  -q --key-quit={K}");
    my_printf("    QUIT the game using the K key (def: 'q' key)\n  -p --key");
    my_printf("-pause={K}   PAUSE/RESTART the game using the K key (def: spa");
    my_printf("ce bar)\n  --map-size={row,col} Set the numbers of rows and ");
    my_printf("columns of the map (def: 20,10)\n  -w --without-next    Hide");
    my_printf(" next tetrimino (def: false)\n  -D --debug\t       Debug mo");
    my_printf("de (def: false)\n");
    exit(0);
}
