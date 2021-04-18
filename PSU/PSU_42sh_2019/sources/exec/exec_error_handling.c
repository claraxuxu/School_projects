/*
** EPITECH PROJECT, 2020
** exec_error_handling.c
** File description:
** checks errors in exec.
*/

#include <errno.h>
#include "exec.h"
#include "lib.h"

int execve_error(char *input, char *input_with_path)
{
    struct stat st;

    if (stat(&input_with_path[2], &st) == -1)
        return (error_msg(input, CMD_NOT_FOUND));
    else if (S_ISREG(st.st_mode))
        return (error_msg(input, WRG_ARCH));
    return (error_msg(input, PERM_DENIED));
}

int check_if_directory(char *dir_path)
{
    struct stat st;

    if (my_strncmp(dir_path, "./", 1) == 0)
        return (0);
    if (stat(dir_path, &st) != -1)
        if (S_ISDIR(st.st_mode))
            return (error_msg(dir_path, CMD_NOT_FOUND));
    return (0);
}

int check_if_segfault(int status)
{
    int return_value = 0;

    if (status == 11 || status == 139) {
        my_puterror("Segmentation fault");
        return_value = 139;
        if (WCOREDUMP(status)) {
            my_puterror(" (core dumped)");
            return_value = 134;
        }
        write(2, "\n", 1);
    }
    else if (status == 8 || status == 136) {
        return_value = 136;
        my_puterror("Floating exception");
        if (WCOREDUMP(status)) {
            my_puterror(" (core dumped)");
            return_value = 126;
        }
        write(2, "\n", 1);
    }
    return (return_value);
}
