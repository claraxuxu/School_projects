/*
** EPITECH PROJECT, 2019
** read_file
** File description:
** read filepath
*/

#include "my.h"

int read_file(char *filepath, file_t *file)
{
    if ((file->fd = open(filepath, O_RDONLY)) == -1)
        return (-1);
    file->size = lseek(file->fd, 0, SEEK_END);
    lseek(file->fd, 0, SEEK_SET);
    file->buf = malloc(sizeof(char) * file->size + 1);
    file->len = read(file->fd, file->buf, file->size + 1);
    file->buf[file->len] = 0;
    if (check_map(file->buf) == -1)
        return (-1);
    if (build_tab(file) == -1)
        return (-1);
}
