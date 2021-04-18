/*
** EPITECH PROJECT, 2019
** git_to_name
** File description:
** for myls
*/

#include "../include/my.h"

char *gid_to_name(gid_t gid)
{
    struct group *grp_ptr;
    static char numstr[10];

    if ((grp_ptr = getgrgid(gid)) == NULL) {
        my_itoa(gid,numstr);
        return (numstr);
    }
    else
        return (grp_ptr->gr_name);
}
