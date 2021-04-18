/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** get_start_ind
*/

#include "tetris.h"

char *get_name(int index)
{
    const char *folder = "./tetriminos";
    DIR *rep = opendir(folder);
    struct dirent *reader;
    int i = 0;

    if (rep == NULL)
        return (0);
    while ((reader = readdir(rep))) {
        if (!my_strcmp(".", reader->d_name) || !my_strcmp("..", reader->d_name))
            continue;
        if (i == index && reader->d_type != DT_DIR)
            return (my_strdup(reader->d_name));
        i++;
    }
    closedir(rep);
    free(reader);
    return (NULL);
}

char *get_file_name(char *file_name)
{
    int start = 0;
    char *res;
    int i = 0;

    if ((start = get_tetri_name(file_name)) == -1)
        return (NULL);
    res = malloc(sizeof(char) * (start + 1));
    if (res == NULL)
        return (NULL);
    if (file_name[0] == '.') {
        i++;
        start--;
    }
    res = my_strnuntil_cpy(&file_name[i], start);
    return (res);
}

int get_tetri_name(char *file_name)
{
    int len = 0;
    int start = 0;

    for (; file_name[start] != 0; start++)
        if (file_name[start] == '.' && start > 0)
            break;
    if (file_name[start] == 0)
        return -1;
    return (start);
}

int get_tetriminos(map_t *map, int ind, int num)
{
    DIR *res = opendir("./tetriminos");
    struct dirent *reader;
    char *path;
    int i = 0;
    int out = 0;

    while ((reader = readdir(res)) != NULL) {
        if (!my_strcmp(".", reader->d_name) || !my_strcmp("..", reader->d_name))
            continue;
        if (i == ind && reader->d_type != DT_DIR) {
            path = my_strdup(get_filepath(reader->d_name));
            out = get_info_path(map, path, num);
            closedir(res);
            return (out);
        }
        i++;
    }
    closedir(res);
    free(reader);
    return (0);
}
