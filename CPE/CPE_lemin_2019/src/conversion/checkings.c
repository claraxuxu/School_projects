/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** checkings.c
*/

#include "lemin.h"

int is_a_tunnel(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] < 48 || line[i] > 57) {
            if (line[i] == '-')
                return TUNNEL;
            else if (line[i] == 32)
                return ROOM;
            else
                return ERR;
        }
    }
    return ERR;
}

int what_is_it(char *line)
{
    if (line[0] == 35 && line[1] != 35)
        return COMMENT;
    if (my_strncmp(line, "##start", 7))
        return START;
    if (my_strncmp(line, "##end", 5))
        return END;
    return (is_a_tunnel(line));
}

void proper(char *str)
{
    for (int i = my_strlen(str); str[i] < '0' || str[i] > '9'; i--)
        str[i] = '\0';
}

int how_many_piro(char **anthil, int mode)
{
    int count = 2;

    for (int i = 0; anthil[i] != NULL; i++)
        if (what_is_it(anthil[i]) == mode) {
            proper(anthil[i]);
            count++;
        }
    return count;
}
