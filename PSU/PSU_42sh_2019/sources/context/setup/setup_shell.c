/*
** EPITECH PROJECT, 2020
** setup_shell.c
** File description:
** sets up shell variables and useful files
*/

#include "42sh.h"
#include "lib.h"
#include "env_handling.h"

static void gen_standard_prompt(void)
{
    environ = add_to_env(environ, my_strdup("PROMPT= > "));
}

char *format_getcwd(void)
{
    char *result = malloc(sizeof(char) * 150);

    result = getcwd(result, 150);
    result = append_char(result, '/');
    return (result);
}

char *setup_shell(void)
{
    int fd = open(".42sh_history", O_RDWR | O_APPEND);
    char *path = format_getcwd();

    if (fd == -1)
        fd = open(".42sh_history", O_CREAT, S_IRUSR | S_IWUSR);
    close (fd);
    gen_standard_prompt();
    return (my_strcat(path, ".42sh_history"));
}