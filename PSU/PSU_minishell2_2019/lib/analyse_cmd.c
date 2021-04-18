/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** analyse_cmd.c
*/

#include "my.h"

void analyse_cmd(shell_t *shell, char *ptr)
{
    shell->redi_cmd = malloc(sizeof(char) * my_strlen(ptr));
    for (int i = 0; *ptr != '\0'; ptr++) {
        if (*ptr == '>') {
            *ptr = '\0';
            shell->flag = 1;
            ptr++;
            if (*ptr == '>') {
                *ptr = '\0';
                shell->flag = 2;
                ptr++;
            }
            while (my_isspace(*ptr) && *ptr != '\0') ptr++;
            for (; !my_isspace(*ptr); i++, ptr++)
                shell->redi_cmd[i] = *ptr;
            shell->redi_cmd[i] = '\0';
            while (*ptr != ' ' && *ptr != '\0') ptr++;
            *ptr = '\0';
        }
    }
}