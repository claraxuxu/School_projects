/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** error.h
*/

#ifndef ERROR_H
#define ERROR_H

int my_error(char *buff);
char *my_realloc(char *str, int size);
char *get_info(void);
int check_anthil(char *buff);
int stock_room(char *buff);
int room_is_ok(int *nbr_room, int current);
int check_rooms(char **tmp);
int check_tunnel(char *buff);
int verify(char *str, char search);

#endif