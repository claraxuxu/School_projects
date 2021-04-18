/*
** EPITECH PROJECT, 2019
** build_map
** File description:
** put ships in water
*/

#include "my.h"

void put_ships(file_t *file)
{
    for (int i = 0; i < 4; i++) {
        if (file->tab[i][1] == file->tab[i][3]) {
            for (int j = file->tab[i][2]; j <= file->tab[i][4]; j++)
                file->blank[j - 1][file->tab[i][1] - 1] =
                    file->tab[i][0] + '0';
        }
        else if (file->tab[i][2] == file->tab[i][4]) {
            for (int j = file->tab[i][1]; j <= file->tab[i][3]; j++)
                file->blank[file->tab[i][2] - 1][j - 1] =
                    file->tab[i][0] + '0';
        }
    }
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            file->sec_map[i][j] = '.';
}

void build_map(file_t *file)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            file->blank[i][j] = '.';
    put_ships(file);
}

