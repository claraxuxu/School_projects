/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** game push the box
*/

#include <stdio.h>
#include "include/my.h"
#include <ncurses.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t get_size(char const *filepath)
{
    struct stat buf;

    if (stat(filepath,&buf) == 0)
        return (buf.st_size);
    return (84);
}
void init()
{
    mvprintw(LINES / 2, COLS / 2, "My_sokoban\n" );
	mvprintw(LINES / 2 + 1, COLS / 2, "Author:Clara Yuhui\n" );
	mvprintw(LINES / 2 + 2, COLS / 2, "<-^-v->  Control\n " );
	mvprintw(LINES / 2 + 3, COLS / 2, "press any key to continue...\n");
	getch();
	clear();
}
int loop(soko_t *data)
{
    int c;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    init();
    noecho();
    while (1) {
        printw(data->buf);
        c = getch();
        direction(data, c);
        check_o(data);
        check_die(data);
        check_win(data);
        refresh();
        clear();
    }
    endwin();
}
int load_buf(char const *filepath, soko_t data)
{
    data.size = get_size(filepath);
    data.buf = malloc(sizeof(char) * data.size + 1);
    data.fd = open(filepath,O_RDONLY);
    data.len = read(data.fd, data.buf, data.size);
    data.buf[data.len] = 0;
    data.xp = data.xp -  data.len_line - 1;
    data.ori = malloc(sizeof(char*) * data.size + 1);

    if (check_error(data) == 1)
        exit (84);
    count_buf(&data);
    get_pos(&data);
    loop(&data);
    close(data.fd);
}
int main(int ac, char **av)
{
    soko_t data;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        help();
    else
        load_buf(av[1], data);
    return (0);
}
