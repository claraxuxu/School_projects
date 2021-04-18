/*
** EPITECH PROJECT, 2019
** mode_to_letters
** File description:
** for myls
*/

#include "../include/my.h"

void mode_to_letters_two(int mode, char *str)
{
    if ((mode & S_IROTH))
        str[7] = 'r';
    if ((mode & S_IWOTH))
        str[8] = 'w';
    if ((mode & S_IXOTH))
        str[9] = 'x';
}
void mode_to_letters(int mode, char *str)
{
    my_strcpy(str,"----------");
    if (S_ISDIR(mode))
        str[0] = 'd';
    if (S_ISCHR(mode))
        str[0] = 'c';
    if (S_ISBLK(mode))
        str[0] = 'b';
    if ((mode & S_IRUSR))
        str[1] = 'r';
    if ((mode & S_IWUSR))
        str[2] = 'w';
    if ((mode & S_IXUSR))
        str[3] = 'x';
    if ((mode & S_IRGRP))
        str[4] = 'r';
    if ((mode & S_IWGRP))
        str[5] = 'w';
    if ((mode & S_IXGRP))
        str[6] = 'x';
    mode_to_letters_two(mode,str);
}
