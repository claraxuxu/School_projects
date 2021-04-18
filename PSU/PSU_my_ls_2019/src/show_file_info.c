/*
** EPITECH PROJECT, 2019
** show_file_info
** File description:
** -l result print
*/

#include "../include/my.h"

void show_file_info(char* filename, struct stat *info_p)
{
    char *ctime();
    char modestr[11];

    mode_to_letters(info_p->st_mode,modestr);
    my_putstr(modestr);
    my_printf(" %d ",(int)info_p->st_nlink);
    my_printf("%s ",uid_to_name(info_p->st_uid));
    my_printf("%s ",gid_to_name(info_p->st_gid));
    my_printf("%d ",info_p->st_size);
    write(1,(ctime(&info_p->st_mtime) + 4),
         (my_strlen(ctime(&info_p->st_mtime)) - 13));
    my_printf(" %s\n",filename);
}
