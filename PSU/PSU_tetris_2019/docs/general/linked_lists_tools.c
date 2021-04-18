/*
** EPITECH PROJECT, 2020
** linked_lists_tools
** File description:
** randooms functions that manages linked lists tools
*/

#include "tetris.h"
#include "map.h"

list_t *initialisation(tetris_t *tetris)
{
    list_t *list = malloc(sizeof(*list));
    line *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL) {
        exit(EXIT_FAILURE);
    }

    element->cur_line = my_memset(tetris->map_width, ' ');
    element->next = NULL;
    list->first = element;

    return list;
}

void insertion(list_t *interface, char *str)
{
    line *new = malloc(sizeof(*new));

    new->cur_line = str;
    new->next = interface->first;
    interface->first = new;
}

void delete_node_in_middle_list(list_t *list, int index)
{
    line *previous_one = list->first;
    line *to_delete = previous_one->next;

    for (int i = 0; i < index; i++) {
        previous_one = to_delete;
        to_delete = to_delete->next;
    }
    previous_one->next = to_delete->next->next;
    to_delete->next = NULL;
    free(to_delete);
}

line *points_to(line *list, int line)
{
    int i = 0;

    while (list != NULL && i < line) {
        list = list->next;
        i++;
    }
    return list;
}

list_t *copy(list_t *list_one, list_t *list_two)
{
    line *line_one = list_one->first;
    line *line_two = list_two->first;

    while (line_two != NULL) {
        line_two->cur_line = my_strdup(line_one->cur_line);
        line_two = line_two->next;
        line_one = line_one->next;
    }
    return (list_two);
}