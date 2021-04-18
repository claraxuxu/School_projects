/*
** EPITECH PROJECT, 2020
** get_answer.c
** File description:
** handles api answer and fills answer_t struct
*/

#include "api_answer.h"
#include "lib.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

static void send_command(command_t cmd, float temp, int tmp)
{
    fflush(NULL);
    switch (cmd.expected_response) {
        case NONE:
            dprintf(1, "%s\n", cmd.command);
            break;
        case INT:
            dprintf(1, "%s%i\n", cmd.command, tmp);
            break;
        case FLOAT:
            dprintf(1, "%s%f\n", cmd.command, temp);
            break;
        default:
            dprintf(1, "unknown expected response.\n");
            break;
    }
    fflush(stdin);
}

static void display_answer_content(answer_t ans)
{
    int fd = open(LOGPATH, O_APPEND | O_RDWR);

    dprintf(fd, "\nANSWER CONTENT\n");
    dprintf(fd,"is ok ? %s\n", ans.is_ok == FALSE ? "KO" : "OK");
    dprintf(fd, "%s\n", ans.code_verbose);
    dprintf(fd, "add info:%i\n", (int)ans.misc_info);
    close(fd);
}

static void display_command_content(command_t cmd)
{
    int fd = open(LOGPATH, O_APPEND | O_RDWR);

    dprintf(fd, "\nCOMMAND CONTENT\n");
    dprintf(fd, "command:%s\n", cmd.simplified_command);
    dprintf(fd, "format:%i\n", (int)cmd.value);
    dprintf(fd, "expected response type:%i\n", (int)cmd.expected_response);
    close(fd);
}

static answer_t flush_buffers(char *buffer, command_t cmd, float data, int data_2)
{
    answer_t answer = get_answer_type(buffer, cmd.value);
    int fd = open(LOGPATH, O_APPEND | O_RDWR);

    while (strcmp("Command not found", answer.code_verbose) == 0) {
        dprintf(fd, "RE-READING BUFFER\n");
        send_command(cmd, data, data_2);
        buffer = get_next_line(0);
        dprintf(fd, "received %s.\nanswer format: %i\n\n", buffer, cmd.value);
        answer = get_answer_type(buffer, cmd.value);
    }
    close(fd);
    FREE(buffer);
    return answer;
}

answer_t get_answer(char *command, float data, int data_2)
{
    answer_t answer = init_answer_struct();
    command_t cmd = get_user_cmd(command);
    format_t answer_format = cmd.value;
    char *buffer = NULL;
    int fd;

    send_command(cmd, data, data_2);
    buffer = get_next_line(0);
    if (buffer == NULL)
        exit(84);
    fd = open(LOGPATH, O_APPEND | O_RDWR);
    dprintf(fd, "Sending command %s -- int:%i float:%f\n", cmd.command,
    data_2, data);
    dprintf(fd, "received %s.\n\n", buffer);
    close(fd);
    answer = get_answer_type(buffer, answer_format);
    FREE(cmd.command);
    FREE(cmd.simplified_command);
    return (fflush(NULL), answer);
}
