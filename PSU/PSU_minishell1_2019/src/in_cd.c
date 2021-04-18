/*
** EPITECH PROJECT, 2020
** in_cd
** File description:
** cd command for minishell1
*/

#include "../include/my.h"

void in_cd(mini_t *mini)
{
    char *buf = malloc(sizeof(char) * 200);

    if (my_strcmp(mini->list[0], "cd") != 0)
        return;
    getcwd(mini->input[mini->a], sizeof(mini->input[mini->a]));
    if (mini->a == 0)
        mini->a++;
    else
        mini->a--;
    if (my_strcmp(mini->list[1], "-") == 0)
        my_strcpy(buf, mini->input[mini->a]);
    else
        my_strcpy(buf, mini->list[1]);
    chdir(buf);
}
