/*
** EPITECH PROJECT, 2019
** uid_to_name
** File description:
** for myls
*/

#include "../include/my.h"

char *uid_to_name(uid_t uid)
{
    struct passwd *pw_ptr;
    static char numstr[10];

    if ((pw_ptr = getpwuid(uid)) == NULL) {
        my_itoa(uid,numstr);
        return (numstr);
    }
    else
        return (pw_ptr->pw_name);
}
