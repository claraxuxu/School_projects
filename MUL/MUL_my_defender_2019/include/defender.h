/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** my_defender
*/

#ifndef structures
#define structures

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "struct.h"
#include "short_name.h"

//events
void event_menu(menu_t *m, win_t *w);

// init
sfRenderWindow *createwin(sfRenderWindow *w);
sfText *create_font(sfText *text, char *str, int x, int y);
void init_struct(menu_t *m);
void init_set(menu_t *m);
void init_game(menu_t *m, win_t *w, game_object_t *gol1);
void init_enemy(game_object_t *gol, win_t *w);
void init_golem_walk(game_object_t *gol, win_t *w);

//menu
void init_menu(menu_t *m);
void check_pos_menu(menu_t *m, sfVector2i vect, sfRenderWindow *w);
void event_menu(menu_t *m, win_t *w);
void draw_text_menu(menu_t *m, win_t *w);
void draw_rect_menu(menu_t *m, win_t *w);
void menu(menu_t *m, win_t *w);

//settings
void setting(menu_t *m, win_t *w);
void check_pos_set(sfRectangleShape *a, menu_t *m, sfVector2i vect, win_t *w);
void event_setting(sfRectangleShape *a, menu_t *m, win_t *w);
void chose_vol(menu_t *m, sfVector2i vect,  win_t *w);

//game
void event_game(menu_t *m, win_t *w, game_object_t *g);
void check_pos_game(menu_t *m, sfVector2i vect);

//golem
void move_golem_walk(menu_t *m, game_object_t *gol1, win_t *w);
void set_enemy_sprite(sfSprite *gol, sfTexture *tex);

//mov_enn
void cas_mov(menu_t *m, game_object_t *g);
void move_right(game_object_t *g);
void move_down(game_object_t *g);
void move_up(game_object_t *g);

//destoy
void destroy(menu_t *m, win_t *w);

//lib
int my_strcmp(char *s, char *str);
int my_have(char *str, char a);
int my_strlen(char *s);
int my_getnbr(char *str);
int my_str_isnum(char *str);
char *my_strcat(char *str, char *str2);
char *my_strdup(char *src);
char *my_realloc(char *str, int size);
char *my_itoa(int nb);
int my_atoi(char *src);
char **my_strsplit(char *str, char c);
void my_putstr(char *s);
void print_help();
int button_is_clicked(sfRectangleShape *rect, sfVector2i click_pos);

//init_tower
void init_tower(game_object_t *g);

//dis_tower
void display_tower(char *tour, menu_t *m, win_t *w, game_object_t *g);
void dis_tower1(win_t *w, game_object_t *g, int tour);
void dis_tower2(win_t *w, game_object_t *g, int tour);
void dis_tower3(win_t *w, game_object_t *g, int tour);


#endif