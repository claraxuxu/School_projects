/*
** EPITECH PROJECT, 2019
** get_answer
** File description:
** get user's answer
*/

#include "my.h"

int check_answer(file_t *file, char *line)
{
    if (my_strlen(line) - 1 != 2)
        return (-1);
    if (my_str_isnum(line[1]) == 0 || my_str_isalpha(line[0]) == 0)
        return (-1);
    if (line[0] < 'A' || line[0] > 'H' || line[1] > '8' || line[1] <= '0')
        return (-1);
    return (0);
}
void send_info(file_t *file)
{
    for (int i = 0; i < file->user[0][0]; i++) {
        usleep(100);
        kill(file->id, SIGUSR1);
    }
    usleep(100);
    kill(file->id, SIGUSR2);
    for (int i = 0; i < file->user[1][0]; i++) {
        usleep(100);
        kill(file->id, SIGUSR1);
    }
    usleep(100);
    kill(file->id, SIGUSR2);
}
int get_answer_user(file_t *file)
{
    char *line = NULL;

    size_t len = 0;
    ssize_t nread;
    my_putstr("Attack: ");
    if (getline(&line, &len, stdin) == -1)
        get_answer_user(file);
    if (check_answer(file,line) == -1)
        get_answer_user(file);
    else if (check_answer(file, line) == 0) {
        file->a = line[0];
        file->user[0][0] = my_atoi(line[0] - 16);
        file->user[1][0] = my_atoi(line[1]);
        my_printf("%c%i", file->user[0][0] + '0' + 16, file->user[1][0]);
        send_info(file);
    }
}
