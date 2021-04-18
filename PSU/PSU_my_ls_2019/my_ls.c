/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** rebuild the ls command
*/

#include "include/my.h"

void put_res_part(int mode, struct stat *info, struct dirent *p)
{
    if (mode == LS_L || mode == LS_RL) {
        show_file_info(p->d_name, info);
    }
    else if (mode == LS_NONE)
        my_printf("%s\n",p->d_name);
}
int main(int ac, char **av)
{
    if(ac == 1)
        do_ls(".",LS_NONE);
    else
        check(ac,av);
}
