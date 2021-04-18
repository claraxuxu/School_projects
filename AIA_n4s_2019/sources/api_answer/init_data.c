/*
** EPITECH PROJECT, 2020
** get_answer_type.c
** File description:
** handles api answer and fills answer_t struct
*/

#include "commands.h"
#include "api_answer.h"
#include "lib.h"
#include <stdlib.h>
#include <string.h>

answer_t init_answer_struct(void)
{
    answer_t res = {
        .is_ok = FALSE,
        .code_verbose = NULL,
        .data.format = NOFORMAT,
        .data.data = NULL,
        .misc_info = INFO_ERROR
    };

    return (res);
}

static command_t load_command_info(command_t command)
{
    command_t cmd = {
        .command = my_strdup(command.command),
        .simplified_command = my_strdup(command.simplified_command),
        .value = command.value,
        .expected_response = command.expected_response
    };

    return (cmd);
}

command_t get_user_cmd(char *user_command)
{
    command_t cmd = {
        .command = NULL,
        .simplified_command = NULL,
        .value = NONE,
        .expected_response = NOFORMAT
    };

    if (user_command == NULL || user_command[0] == '\0')
        return (cmd);
    for (int i = 0; commands[i].command != NULL; i++) {
        if (strcmp(user_command, commands[i].simplified_command) == 0)
            return (load_command_info(commands[i]));
    }
    return (cmd);
}