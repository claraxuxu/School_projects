/*
** EPITECH PROJECT, 2020
** read_user_input.c
** File description:
** fetches user interaction
*/

#include "lib.h"
#include "input_handling.h"
#include <unistd.h>

map_t *read_user_input(char *hist_filepath)
{
    map_t *grp = map_create(5, MB_STR);
    char *input = get_next_line(0);

    update_command(input, hist_filepath);
    if (!regex_extract(input, REGEX_CMD, grp))
        return NULL;
    if (map_get(grp, 0) == NULL)
        return NULL;
    return (grp);
}