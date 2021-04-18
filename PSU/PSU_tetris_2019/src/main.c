/*
** EPITECH PROJECT, 2019
** main
** File description:
** main file for tetris
*/

#include "tetris.h"

void init_ncurses(tetris_t *data)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    data->game.win = newwin(LINES, COLS, 0, 0);
}

int main(int ac, char **av)
{
    tetris_t tetris;

    srand(time(NULL));
    instance_str(&tetris);
    if (get_param(&tetris, av, ac))
        help_part(av[0]);
    analyse_params(&tetris, ac, av);
    prepare_game(&tetris);
    return (0);
}

static void detect_key_pressed(void)
{
    struct termios term;
    char buff;

    ioctl(0, TCGETS, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    term.c_cc[VMIN] = 1;
    term.c_cc[VTIME] = 0;
    ioctl(0, TCSETS, &term);
    read(0, &buff, 1);
}

void analyse_params(tetris_t *tetris, int ac, char **av)
{
    if (tetris->wants_help == true)
        help_part(av[0]);
    debug(tetris);
    if (tetris->is_debug_on)
        detect_key_pressed();
    init_ncurses(tetris);
}
