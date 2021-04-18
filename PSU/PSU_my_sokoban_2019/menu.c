/*
** claraxuxu, 2019
** my_sokoban
** File description:
** ncurses menu
*/

#include <stdio.h>
#include "include/my.h"
#include <ncurses.h>
#include <sys/stat.h>
#include <fcntl.h>

void init()
{
    mvprintw(LINES / 2, COLS / 2, "MY MENU\n" );
	mvprintw(LINES / 2 + 1, COLS / 2, "Author:Clara xuxu\n" );
	mvprintw(LINES / 2 + 2, COLS / 2, "<-^-v->  Control\n " );
	mvprintw(LINES / 2 + 3, COLS / 2, "press any key to continue...\n");
	getch();
	clear();
}

int main(int ac, char **av)
{
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    init();
    noecho();
    endwin();
}
