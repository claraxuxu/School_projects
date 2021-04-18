/*
** EPITECH PROJECT, 2019
** put_map
** File description:
** put ships in water
*/

#include "my.h"

void put_enemy_map(file_t *file)
{
    my_printf("enemy's positions:\n");
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%i|",i + 1);
        for (int j = 0; j < 8; j++) {
            if (j < 7)
                my_printf("%c ",file->sec_map[i][j]);
            if (j == 7)
                my_printf(".\n");
        }
    }
    my_putchar('\n');
}

void put_map(file_t *file)
{
    my_printf("my positions:\n");
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%i|",i + 1);
        for (int j = 0; j < 8; j++) {
            if (j < 7)
                my_printf("%c ",file->blank[i][j]);
            if (j == 7)
                my_printf("%c\n",file->blank[i][j]);
        }
    }
    my_putchar('\n');
    put_enemy_map(file);
}
