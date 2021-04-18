/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** instance_str.c
*/

#include "tetris.h"

void get_info_from_path(map_t *map, char *path, int num)
{
    char *buf = read_file(path);
    char *first_line = my_strdup(get_line(buf, 0));

    if (first_line == NULL)
        return;
    map->size_y = my_atoi(first_line[0]);
    map->size_x = my_atoi(first_line[2]);
    free(first_line);
}

int get_te(map_t *map, int ind, int num)
{
    DIR *res = opendir("./tetriminos");
    struct dirent *reader;
    char *path;
    int i = 0;

    while ((reader = readdir(res))) {
        if (!my_strcmp(".", reader->d_name) || !my_strcmp("..", reader->d_name)
        || reader->d_type == DT_DIR)
            continue;
        if (i == ind) {
            path = my_strdup(get_filepath(reader->d_name));
            get_info_from_path(map, path, num);
            closedir(res);
            return (0);
        }
        i++;
    }
    closedir(res);
    free(reader);
}

void get_info_map(tetris_t *tetris)
{
    int *elem = NULL;
    tetris->map->top_width = 0;
    tetris->map->top_height = 0;
    tetris->num_tetri = num_tetrimi();

    elem = get_sorted_list(tetris);
    for (int i = 0; i < tetris->num_tetri; i++) {
        get_te(tetris->map, elem[i], i);
        if (tetris->map->size_y > tetris->map->top_width)
            tetris->map->top_width = tetris->map->size_y;
        if (tetris->map->size_x > tetris->map->top_height)
            tetris->map->top_height = tetris->map->size_x;
    }
    free(elem);
}

void instance_str(tetris_t *tetris)
{
    tetris->map = malloc(sizeof(*tetris->map));
    tetris->fill_lines = 0;
    tetris->wants_help = false;
    tetris->is_debug_on = false;
    tetris->game.go_right = 261;
    tetris->game.go_left = 260;
    tetris->game.turn_it = 32;
    tetris->game.fall_down = 'x';
    tetris->game.quit = 'q';
    tetris->game.pause = 'p';
    tetris->len = 0;
    tetris->score = 0;
    tetris->level = 1;
    tetris->is_pause = false;
    tetris->able_preview = true;
    tetris->map_width = 20;
    tetris->map_height = 10;
    tetris->map->tetri_head_line = 0;
    get_info_map(tetris);
}
