/*
** EPITECH PROJECT, 2020
** get_tetri
** File description:
** functions that get a random tetri and splits it into a tabgen.
*/

#include "tetris.h"
#include "map.h"

char **get_tabgen(char *str)
{
    int total_line = count_that_char(&str[1], '\n') + 1;
    char **dest = malloc(sizeof(char *) * (total_line + 1));
    int cur_line = 0;
    int i = 1;

    for (; i < my_strlen(str); i++, cur_line++) {
        dest[cur_line] = strcpy_until(&str[i], '\n');
        i += strlen_until(&str[i], '\n');
    }
    dest[cur_line] = NULL;
    return dest;
}

void free_tab(char **tab)
{
    for (int lines = 0; tab[lines] != NULL; lines++)
        free(tab[lines]);
    free(tab);
}

int find_spaces_to_be_in_middle(char *str, int width)
{
    int fst_bound = 0;
    int last_bound = 0;
    int len = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '*')
            last_bound = i;
    }
    for (int i = 0; str[i] != 0; i++)
        if (str[i] == '*') {
            fst_bound = i;
            break;
        }
    len = last_bound - fst_bound + 1;
    return (width - len) / 2;
}

char **put_in_middle(char **tetrimino, int width)
{
    int total_lines = count_that_lines(tetrimino);
    int marge = (width - my_strlen(tetrimino[0])) / 2;
    char **middle_tetri = malloc(sizeof(char *) * (total_lines + 1));
    int cur_line = 0;
    int total_cols = 0;

    for (int cur_col = 0; cur_line < total_lines; cur_line++) {
        total_cols = my_strlen(tetrimino[cur_line]);
        middle_tetri[cur_line] = my_memset(width, ' ');
        for (int i = marge, cur_col = 0; cur_col < total_cols;
            cur_col++, i++)
            middle_tetri[cur_line][i] = tetrimino[cur_line][cur_col];
    }
    middle_tetri[cur_line] = NULL;
    free_tab(tetrimino);
    return middle_tetri;
}

char **get_tetri(tetris_t *data, display_t *disp)
{
    int choose = 0;
    char **tetrimino = NULL;

    choose = rand() % (data->num_tetri - 1) + 1;
    tetrimino = get_tabgen(data->map->tetri[choose]);
    tetrimino = put_in_middle(tetrimino, data->map_width);
    return (tetrimino);
}
