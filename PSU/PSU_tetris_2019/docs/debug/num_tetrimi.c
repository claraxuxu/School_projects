/*
** EPITECH PROJECT, 2019
** num_tetrimi.c
** File description:
** get num of files in tetrimino folder
*/

#include "tetris.h"

int num_tetrimi(void)
{
    struct dirent *reader;
    DIR *res = opendir("./tetriminos");
    int i = 0;

    if (res == NULL)
        return (0);
    while (reader = readdir(res)) {
        if (!my_strcmp(".", reader->d_name) || !my_strcmp("..", reader->d_name)
        || reader->d_type == DT_DIR)
            continue;
        i++;
    }
    closedir(res);
    free(reader);
    return (i);
}
