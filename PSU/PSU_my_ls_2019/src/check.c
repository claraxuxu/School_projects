/*
** EPITECH PROJECT, 2019
** check
** File description:
** check mode of input
*/

#include "../include/my.h"

int check(int ac, char **av)
{
    int mode = LS_NONE;
    int have_file_param = 0;
    int cal = 0;

    while (ac > 1) {
        ac--;
        av++;
        cal = analyze(*av);
        if (cal != -1)
            mode += cal;
        else {
            have_file_param = 1;
            for (; ac >= 1; ac--,av++)
                do_ls(*av,mode);
        }
    }
    if (have_file_param == 0)
        do_ls(".",mode);
}
