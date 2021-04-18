/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** conversion.h
*/

#include "lemin.h"

#ifndef CONVERSION_H
#define CONVERSION_H

#define TUNNEL 1
#define ROOM 2
#define COMMENT 3
#define START 4
#define END 5
#define ERR 6
#define INF 1000000
typedef struct info
{
    char **pipe;
    char **room;
    char *start;
    char *end;
    int graph[110][110];
    int j;
    int k;
    int j1;
    int k1;
    int dis;
    int n;
    int m;
}info_t;
/*--------- conversion.c --------*/
int file_conversion(info_t *info, char **anthil);
void display_parsing(info_t *info, int p, int r);
void start_end_case(info_t *info, char **anthil, int *i);


/*--------- checkings.c --------*/
int is_a_tunnel(char *line);
int what_is_it(char *line);
void proper(char *str);
int how_many_piro(char **anthil, int mode);

#endif