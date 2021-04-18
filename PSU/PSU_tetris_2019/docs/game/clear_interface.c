/*
** EPITECH PROJECT, 2020
** clean_interface
** File description:
** function that cleans interface
*/

#include "tetris.h"
#include "map.h"

list_t *clear_interface(list_t *interface, tetris_t *data)
{
    char *empty_line = my_memset(data->map_width, ' ');

    for (int line = 0; line < data->map_height; line++)
        insertion(interface, empty_line);
    return interface;
}

char *clean_line(char *str)
{
    for (int i = 0; str[i] != 0; str[i] = ' ', i++);
    return str;
}

list_t *clean(list_t *interface)
{
    line *current = interface->first;

    while (current != NULL) {
        current->cur_line = clean_line(current->cur_line);
        current = current->next;
    }
    return interface;
}
