/*
** EPITECH PROJECT, 2019
** read_file
** File description:
** read file
*/

#include "tetris.h"

char *read_file(char *path)
{
    int fd = open(path, O_RDONLY);
    char *buf = NULL;
    struct stat st;
    int len = 0;

    if (fd == -1)
        return NULL;
    stat(path, &st);
    len = st.st_size;
    buf = malloc(sizeof(char) * (len + 1));
    read(fd, buf, len);
    buf[len] = 0;
    return (buf);
}
