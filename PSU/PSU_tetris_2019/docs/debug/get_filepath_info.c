/*
** EPITECH PROJECT, 2019
** get_filepath_info
** File description:
** get buf in file and get filepath
*/

#include "tetris.h"

char *get_filepath(char *name)
{
    char *filepath = malloc(sizeof(char) *
    (my_strlen("./tetriminos") + my_strlen(name) + 2));

    my_strcpy(filepath, "./tetriminos");
    my_strcat(filepath, "/");
    my_strcat(filepath, name);
    return (filepath);
}

char *get_line(char *buf, int begin)
{
    char *line;
    int len = 0;
    int j = 0;

    if (buf == NULL || buf[0] == 0)
        return NULL;
    for (int i = begin; i < my_strlen(buf) && buf[i] != '\n'; i++)
        len++;
    if (len == 0)
        return (NULL);
    line = malloc(sizeof(char) * len + 1);
    for (j = begin; buf[j] && buf[j] != '\n'; j++)
        line[j - begin] = buf[j];
    line[j - begin] = 0;
    return (line);
}

int get_info_path(map_t *map, char *path, int num)
{
    char *buf = read_file(path);
    char *first_line = my_strdup(get_line(buf, 0));
    int j = 0;

    if (buf == NULL || buf[0] == 0 || first_line == NULL || first_line[0] == 0
    || find_char(first_line, ' ') != 2 || check_buf(buf, first_line) == 0)
        return (0);
    map->buf = map->tetri[num] = malloc(sizeof(char) * (my_strlen(buf) -
    my_strlen(first_line) + 2));
    map->size_y = my_atoi(first_line[0]);
    map->size_x = my_atoi(first_line[2]);
    map->color = my_atoi(first_line[4]);
    for (int i = my_strlen(first_line); buf[i] != 0; i++, j++)
        map->buf[j] = buf[i];
    map->buf[j] = 0;
    for (int i = 0; i < my_strlen(map->buf); i++)
        map->tetri[num][i] = map->buf[i];
    free(first_line);
    return (1);
}
