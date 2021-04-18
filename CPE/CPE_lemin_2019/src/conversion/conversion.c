/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** conversion.c
*/

#include "lemin.h"

char *my_strdup(char *src)
{
    char *p_src = NULL;
    int count = 0;
    char *new_addr;

    if (src == NULL)
        return (NULL);
    p_src = src;
    while (*p_src != '\0') {
        count++;
        p_src++;
    }
    new_addr = malloc(sizeof(char) * (count + 1));
    p_src = src;
    while (*p_src  != '\0')
        *new_addr++ = *p_src++;
    *new_addr = '\0';
    return (new_addr - (count));
}

void display_start_end(info_t *info, char **anthil, int i)
{
    my_putstr(anthil[i]);
    my_putchar('\n');
    my_putstr(anthil[i + 1]);
    my_putchar('\n');
    if (what_is_it(anthil[i]) == START)
        info->start = my_strdup(anthil[i + 1]);
    else if (what_is_it(anthil[i]) == END)
        info->end = my_strdup(anthil[i + 1]);
}

void start_end_case(info_t *info, char **anthil, int *i)
{
    static char *tmp = NULL;
    static int start_displayed = 0;

    if (what_is_it(anthil[*i]) == START) {
        display_start_end(info, anthil, *i);
        start_displayed++;
        *i += 1;
    } if (what_is_it(anthil[*i]) == END && start_displayed == 1) {
        display_start_end(info, anthil, *i);
        *i += 1;
    } if (what_is_it(anthil[*i]) == END && start_displayed == 0) {
        tmp = anthil[*i + 1];
        info->end = my_strdup(tmp);
        *i += 1;
    } if (tmp != NULL && start_displayed == 1) {
        my_putstr("##end\n");
        my_putstr(tmp);
        my_putchar('\n');
        start_displayed++;
    }
}

void display_parsing(info_t *info, int p, int r)
{
    my_sort_params(info->pipe, p);
    my_sort_params(info->room, r);
    for (int i = 0; i < r; i++) {
        my_putstr(info->room[i]);
        my_putchar('\n');
    }
    my_putstr("#tunnels\n");
    for (int i = 0; i < p; i++) {
        my_putstr(info->pipe[i]);
        my_putchar('\n');
    }
    my_putstr("#moves\n");
}

int file_conversion(info_t *info, char **anthil)
{
    info->pipe = malloc(sizeof(char *) * how_many_piro(anthil, TUNNEL));
    info->room = malloc(sizeof(char *) * how_many_piro(anthil, ROOM));
    int p = 0;
    int r = 0;

    my_putstr("#number_of_ants\n");
    my_put_nbr(my_getnbr(anthil[0]));
    my_putstr("\n#rooms\n");

    for (int i = 1; anthil[i] != NULL; i++) {
        if (what_is_it(anthil[i]) == ROOM) {
            info->room[r] = anthil[i];
            r++;
        } else if (what_is_it(anthil[i]) == TUNNEL) {
            info->pipe[p] = anthil[i];
            p++;
        }
        start_end_case(info, anthil, &i);
    }
    info->pipe[p] = NULL;
    info->room[r] = NULL;
    display_parsing(info, p, r);
    return (0);
}