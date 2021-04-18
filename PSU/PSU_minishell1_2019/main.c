/*
** EPITECH PROJECT, 2020
** main
** File description:
** minishell1
*/

#include "include/my.h"

void def_list(char *ptr, mini_t *mini)
{
    mini->argc = 0;
    while (*ptr != '\0') {
        if (!my_isspace(*ptr)) {
            mini->list[mini->argc] = ptr;
            mini->argc++;
            while (!my_isspace(*ptr) && *ptr != '\0')
                ptr++;
            *ptr = '\0';
            ptr++;
            continue;
        }
        ptr++;
    }
}
void cmd_list(char *ptr, mini_t *mini)
{
    int pid;

    def_list(ptr, mini);
    if (check_input(mini) == 0) {
        mini->list[mini->argc] = NULL;
        find_in_env(mini);
        pid = fork();
        if (pid == 0) {
            for (int i = 0; i < mini->nbr; i++) {
                mini->lenv[i] = my_strcat(my_strcat(mini->lenv[i], "/"),
                                          mini->list[0]);
                execve(mini->lenv[i],mini->list,mini->cp_env);
            }
            exit(0);
        }
        wait(NULL);
    }
}
void other_cmd(mini_t *mini)
{
    if (!my_strcmp(mini->list[0], "cd"))
        in_cd(mini);
    else if (!my_strcmp(mini->list[0], "setenv"))
        get_setenv(mini);
    else if (!my_strcmp(mini->list[0], "unsetenv"))
        get_unsetenv(mini);
}
int main(UNUSED int ac, UNUSED char **av, char **env)
{
    char *tmp = NULL;
    char *ptr = NULL;

    mini_t mini;
    def_env(&mini, env);
    while (1) {
        print_prompt();
        size_t len1 = 0;
        ssize_t nread = 0;
        nread = getline(&tmp, &len1, stdin);
        if (nread == -1) {
            my_printf("exit\n");
            exit (0);
        }
        ptr = tmp;
        cmd_list(ptr,&mini);
        other_cmd(&mini);
    }
    return (0);
}
