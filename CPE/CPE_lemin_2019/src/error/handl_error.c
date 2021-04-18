/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** lemin
*/

#include "lemin.h"

int check_rooms(char **tmp)
{
    int room = 0;

    for (int y = 0; tmp[y]; y++)
        if (verify(tmp[y], 32) == 2 && my_strlen(tmp[y]) < 8) {
            room++;
        }
    return room;
}

int room_is_ok(int *nbr_room, int current)
{
    for (int nb = 0; nb < current; nb++) {
        if (nbr_room[current] == nbr_room[nb])
            return -1;
    }
    return 0;
}

int stock_room(char *buff)
{
    char **tmp = my_str_retab(buff);
    int *nbr_room = malloc(sizeof(int) * check_rooms(tmp));
    int i = 0;

    for (int y = 0; tmp[y]; y++)
        if (verify(tmp[y], 32) == 2 && my_strlen(tmp[y]) < 8) {
            nbr_room[i] = my_getnbr(tmp[y]);
            if (room_is_ok(nbr_room, i) == -1)
                return -1;
        i++;
        }
    return 0;
}

char *my_realloc(char *str, int size)
{
    char *new = malloc(my_strlen(str) + size);

    my_strncpy(new, str, my_strlen(str) + 1);
    free(str);
    return (new);
}

char *get_info(void)
{
    char str[2];
    char *anthil = malloc(sizeof(char) * 2);

    str[1] = '\0';
    for (int i = 1; read(0, str, 1) != 0; i++) {
        anthil[i - 1] = str[0];
        anthil[i] = '\0';
        anthil = my_realloc(anthil, 2);
        anthil[i + 1] = '\0';
    }
    return (anthil);
}