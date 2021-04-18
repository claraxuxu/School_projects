/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "lib.h"
#include "istl/utility.h"
#include "istl/hash_table.h"
#include "istl/string.h"
#include "input_module.h"
#include "input_handling.h"
#include "exec.h"

int input_read(vector_t *expr, char *hfile)
{
    char *input = NULL;
    int res = 0;

    if (expr == NULL)
        return (-1);
    res = prompt_cmd(&input, hfile);
    if (res != 0)
        return (res);
    prompt_format(input, expr);
    return (0);
}

int prompt_cmd(char **prompt, char *hfile)
{
    if (prompt == NULL)
        return (-1);
    (*prompt) = get_next_line(0);
    if (*prompt == NULL)
        return (-1);
    update_command(*prompt, hfile);
    return (0);
}

int prompt_format(char const *prompt, vector_t *expr)
{
    map_t *match = map_create(10, MB_STR);
    cmd_t cmd = (cmd_t) {NULL, NULL, "", {-1, -1}};
    string_t *str = NULL;

    if (match == NULL)
        return (map_free(&match), -1);
    if (regex_extract(prompt, REGEX_CMD, match) != TRUE)
        return (map_free(&match), -1);
    cmd_from_match(match, &cmd);
    vector_push(expr, &cmd);
    while (map_get(match, 4) != NULL) {
        str = map_get(match, 4);
        regex_extract(str_cstr(str), REGEX_CMD, match);
        cmd = (cmd_t) {NULL, NULL, "", {-1, -1}};
        cmd_from_match(match, &cmd);
        expand_cmd_args(&cmd);
        vector_push(expr, &cmd);
    }
    return (0);
}

int input_eval(vector_t *expr)
{
    cmd_t *cmd = NULL;
    int res = 0;
    cmd_t *last = NULL;
    int rw[2] = {-1, -1};

    if (expr == NULL)
        return (-1);
    for (uint_t i = 0; i < vector_len(expr); i++) {
        cmd = vector_pull(expr, i);
        if (cmd_pipes(last)) {
            rw[OUT] = last->pipe[OUT];
            rw[IN] = -1;
        }
        if (cmd_pipes(cmd)) {
            pipe(cmd->pipe);
            rw[IN] = cmd->pipe[IN];
        }
        expand_cmd_args(cmd);
        res = exec(cmd, 0, rw);
        last = cmd;
    }
    vector_narrow(expr);
    return (res);
}

// if (res == EX_ERR) {
//      if (cmd->op == "||")
//          continue;
//      else
//          break;
// }
// if (res == EX_OK) {
//      if (cmd->op == "||") {
//          break;
//      } else
//          continue;
// }
