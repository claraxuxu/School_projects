/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** log_file_handler.c
*/

#include "api_answer.h"
#include "macros.h"
#include "loop.h"
#include "api_quest.h"
#include "lib.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void create_logpath(cchar_t *filepath)
{
    int fd = open(filepath, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);

    dprintf(fd, "Successfully created log file.\n\n");
    close(fd);
}