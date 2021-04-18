/*
** EPITECH PROJECT, 2020
** my
** File description:
** header needed by tetris project.
*/

#ifndef _MY_H
#define _MY_H

#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <ncurses.h>
#include <curses.h>
#include <stdbool.h>
#include <time.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <fcntl.h>
#include <getopt.h>
#include <unistd.h>
#include <getopt.h>

static struct option lopt[] =
{
    {"help",    no_argument,    NULL,   'h'},
    {"debug",   no_argument,        NULL,   'D'},
    {"without-next",    no_argument,    NULL,   'W'},
    {"level",   required_argument,  NULL,   'L'},
    {"key-left",    required_argument,  NULL,   'l'},
    {"key-right",   required_argument,  NULL,   'r'},
    {"key-turn",    required_argument,  NULL,   't'},
    {"key-drop",    required_argument,  NULL,   'd'},
    {"key_quit",    required_argument,  NULL,   'q'},
    {"key_pause",   required_argument,  NULL,   'p'},
    {"map-size",    required_argument,  NULL,   'm'},
    {NULL,  0,  NULL,   0},
};

typedef struct game
{
    WINDOW *win;
    int pause;
    int go_right;
    int go_left;
    int turn_it;
    int fall_down;
    int quit;
} game_t;

typedef struct map
{
    int num_tetris;
    char *buf;
    int top_width;
    int top_height;
    int size_y;
    int size_x;
    int x;
    int tetri_head_line;
    int color;
    char *name;
    char **tetri;
} map_t;

typedef struct tetris
{
    struct map *map;
    game_t game;
    int num_tetri;
    int len;
    int score;
    int level;
    bool is_pause;
    int map_width;
    int map_height;
    bool wants_help;
    bool is_debug_on;
    bool able_preview;
    int preview;
    int fill_lines;
    int speed;
} tetris_t;

//printf and basic fonctions
void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_getnbr(char *str);
int my_atoi(char src);
int my_atoistr(char *src);
int my_str_isalpha(char *str);
char *my_strncpy(char *res, char *line, int len);
char *my_strnuntil_cpy(char *str, int n);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char *str1, char *str2);
char *my_strcat(char *dest, const char *src);
char **my_str_to_word_array(const char *str, char separator);
void split_str(const char *str, char separator,
char **result, char *content);
char *my_strdup(char *src);
int my_str_isnum(char *str);
char *my_memset(int size, char with_what);
int my_printf(char *format, ...);
char *concat(char *s1, char *s2);
char *sub_concat(char *s1, char *s2);

// basic arrays stuff
int *tabdup(int tab);
int intlen(int *tab);
int *sub_intconcat(int *tab1, int tab2);
int *intconcat(int *tab1, int tab2);
int array_cmp(int *tab);
int count_that_lines(char **tab);

//prepare the game
void instance_str(tetris_t *tetris);
void extract_size(tetris_t *tetris);
void analyse_params(tetris_t *tetris, int ac, char **av);
void prepare_game(tetris_t *tetris);
void help_part(char *binary_name);

//check game
int *get_biggest_tetri_dimensions(map_t *map);
int sort_by_biggest(int *array);
int check_buf(char *buf, char *first_line);
bool check_unexpected_argument(int);

//outils
int find_char(char *str, char find);
int num_tetrimi(void);
char *read_file(char *path);

//manage_params
int get_param(tetris_t *tetris, char **argv, int argc);
int get_param2(int return_value, tetris_t *tetris, char *binary_name);
int get_optarg(char *optarg, char * binary_name);
int get_nb_optarg(char *optarg, char *binary_name);
int check_key_unicity(game_t game);
int check_keys(tetris_t *tetris);
int check_coherence(tetris_t *tetris, int argc);

//get names
char *get_name(int index);
int get_tetri_name(char *file_name);
char *get_file_name(char *file_name);

//debug
void debug(tetris_t *tetris);
void debug_reader(tetris_t *, int i, int num);

//display
void display_keys(tetris_t *tetris);
void display_tetri(map_t *);
void display_tetriminos(tetris_t *tetris);

//get file infos
char *get_filepath(char *name);
char *get_line(char *buf, int begin);
int get_info_path(map_t *map, char *path, int num);
int get_tetriminos(map_t *map, int ind, int num);

//get_tetri
char **get_tabgen(char *str);
void free_tab(char **tab);
char **put_in_middle(char **tetrimino, int width);
char **get_tetri(tetris_t *data, display_t *disp);

//sort
int *get_sorted_list(tetris_t *);
int my_sort_alpha(int *elems, char **src, int success);
list_t *clear_interface(list_t *interface, tetris_t *data);
bool last_pause_display_condition(clock_t elapsed);
void game_loop(tetris_t *data, display_t *display);

//linked_list_tools
list_t *initialisation(tetris_t *tetris);
void insertion(list_t *interface, char *str);
void delete_node_in_middle_list(list_t *list, int index);
line *points_to(line *list, int line);
list_t *copy(list_t *list_one, list_t *list_two);

//handle event
void handle_input_events(tetris_t *data, display_t *disp, int key);
void handle_game_events(tetris_t *data, display_t *disp, clock_t time,
clock_t elapsed);
void quit_the_game(tetris_t *data, display_t *disp);
void put_pause(tetris_t *data);
void moves_gestion(tetris_t *data, display_t *disp, int key);
bool u_dont_loose(tetris_t *data, display_t *dis);

//tetrimino_moves
char **move_to_right(char **tetri);
char **move_to_left(char **tetri);
char **turn_it(char **tetri);
line *head_map_calc_line(line *map_calc_line);
list_t *fall_a_bit(list_t *interface, list_t *map_calc,
char **tetri, tetris_t *tetris);

//check_move_ab
bool you_can_turn_it(char **tetri, tetris_t *data);
bool is_a_valid_move(char **tetri, bool is_left);
bool line_has_been_fill(list_t *map_calc, char **tetri, tetris_t *data);

//counter_functions
int strlen_until(char *str, char until);
int count_that_lines(char **tab);
int count_that_char(char *str, char c);
char *strcpy_until(char *str, char until);

//level_upgrade
int this_line_is_full(list_t *map_calc, int col_max);
list_t *upgrade_map_by_removing_line(list_t *interface, tetris_t *data,
int line);
void upgrade_level(tetris_t *data);

//display_interface
void display_map(display_t *disp, tetris_t *data);
void display_interface(list_t *interface, tetris_t *tetris, display_t *disp);
void display_board(tetris_t *data, display_t *disp);
list_t *calc_map_and_tetri(display_t *disp, tetris_t *data);
void display_next_tetri(tetris_t *data, display_t *disp);

//clear_interface
list_t *clear_interface(list_t *interface, tetris_t *data);
char *clean_line(char *str);
list_t *clean(list_t *interface);
#endif
