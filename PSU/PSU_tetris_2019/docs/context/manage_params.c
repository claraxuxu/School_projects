/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** manage_params.c
*/

#include "tetris.h"

int get_param(tetris_t *tetris, char **argv, int argc)
{
    struct lopt;
    int return_value = 0;
    int option_index = 0;
    char *list_opt = my_strdup("DwhL:l:t:r:d:q:p:m:");

    while ((return_value = getopt_long(argc, argv, list_opt,
            lopt, &option_index)) != -1) {
        if (return_value == 0 || return_value == '?' || return_value == ':')
            return (84);
        if (return_value == 'D')
            tetris->is_debug_on = true;
        if (return_value == 'w')
            tetris->able_preview = false;
        if (return_value == 'L')
            tetris->level = get_nb_optarg(optarg, argv[0]);
        if (return_value == 'l')
            tetris->game.go_left = get_optarg(optarg, argv[0]);
        get_param2(return_value, tetris, argv[0]);
    }
    return check_coherence(tetris, argc);
}

int get_param2(int return_value, tetris_t *tetris, char *binary_name)
{
    switch (return_value) {
    case 'h': tetris->wants_help = true;
        break;
    case 't': tetris->game.turn_it = get_optarg(optarg, binary_name);
        break;
    case 'r': tetris->game.go_right = get_optarg(optarg, binary_name);
        break;
    case 'd': tetris->game.fall_down = get_optarg(optarg, binary_name);
        break;
    case 'q': tetris->game.quit = get_optarg(optarg, binary_name);
        break;
    case 'p': tetris->game.pause = get_optarg(optarg, binary_name);
        break;
    case 'm': extract_size(tetris);
        break;
    case 0: case ':': case '?': case '*': help_part(binary_name);
    }
    return (0);
}

int check_key_unicity(game_t game)
{
    int *keys = NULL;
    int return_value = 0;

    keys = intconcat(keys, game.go_right);
    keys = intconcat(keys, game.go_left);
    keys = intconcat(keys, game.fall_down);
    keys = intconcat(keys, game.quit);
    keys = intconcat(keys, game.turn_it);
    keys = intconcat(keys, game.pause);
    if (array_cmp(keys))
        return_value = 84;
    else return_value = 0;
    free(keys);
    return (return_value);
}

int check_coherence(tetris_t *tetris, int argc)
{
    int return_value = 0;

    if (tetris->level <= 0)
        return 84;
    if (check_key_unicity(tetris->game))
        return 84;
    if (check_unexpected_argument(argc))
        return 84;
    if (tetris->map->top_height > tetris->map_height ||
        tetris->map->top_width > tetris->map_width)
        return 84;
    return return_value;
}
