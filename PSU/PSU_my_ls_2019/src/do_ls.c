/*
** EPITECH PROJECT, 2019
** do_ls_123
** File description:
** for myls
*/

#include "../include/my.h"

void do_ls_three(dols_t *ls, char *dirname, struct dirent *p)
{
    struct stat info;

    my_strcpy(ls->complete_d_name,dirname);
    my_strcat(ls->complete_d_name,"/");
    my_strcat(ls->complete_d_name,p->d_name);
    if (stat(ls->complete_d_name,&info) == -1)
        perror(ls->complete_d_name);
    else
        put_res_part(ls->mode,&info,p);
    if (ls->mode == LS_R) {
        if (S_ISDIR(info.st_mode)) {
            my_printf("%s\n",p->d_name);
            my_strcpy (ls->dirs[ls->dir_count],ls->complete_d_name);
            ls->dir_count++;
        }
        else
            my_printf("%s\n", p->d_name);
    }
}
void do_ls_two(char *dirname, int mode)
{
    dols_t ls;
    ls.mode = mode;
    struct dirent *p;
    ls.dir_count = 0;
    DIR *dir_ptr = opendir(dirname);

    while (p = readdir(dir_ptr)) {
        if (ls.mode < 200 && p->d_name[0] == '.')
            continue;
        do_ls_three(&ls,dirname,p);
    }
    if (ls.mode == LS_R) {
        my_putchar('\n');
        for (int i = 0; i < ls.dir_count; i++) {
            my_printf("%s:\n",ls.dirs[i]);
            do_ls(ls.dirs[i],LS_R);
            my_putchar('\n');
        }
    }
}
void do_ls(char *dirname, int mode)
{
    DIR *dir_ptr;

    if ((dir_ptr = opendir(dirname)) == NULL)
        exit (84);
    else {
        if (mode == LS_D)
            my_printf("%s\n",dirname);
        else
            do_ls_two(dirname,mode);
        closedir(dir_ptr);
    }
}
