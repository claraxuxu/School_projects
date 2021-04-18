/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** display.c
*/

#include "tetris.h"

void display_set(int button)
{
    if (button == 32)
        my_printf("(space)\n");
    else {
        switch (button){
        case (258): my_printf("^EOB\n");
            break;
        case (259): my_printf("^EOA\n");
            break;
        case (260): my_printf("^EOD\n");
            break;
        case (261): my_printf("^EOC\n");
            break;
        default: my_printf("%c\n", button);
            break;
        }
    }
}

void display_keys(tetris_t *tetris)
{
    my_printf("Key Left : ");
    display_set(tetris->game.go_left);
    my_printf("Key Right : ");
    display_set(tetris->game.go_right);
    my_printf("Key Turn : ");
    display_set(tetris->game.turn_it);
    my_printf("Key Drop : ");
    display_set(tetris->game.fall_down);
    my_printf("Key Quit : ");
    display_set(tetris->game.quit);
    my_printf("Key Pause : ");
    display_set(tetris->game.pause);
    my_printf("Next : ");
    if (tetris->able_preview == 0)
        my_printf("No\n");
    else my_printf("Yes\n");
    my_printf("Level : %i\n", tetris->level);
    my_printf("Size : %i*%i\n", tetris->map_width, tetris->map_height);
    my_printf("Tetriminos : %i\n", tetris->num_tetri);
}

void display_tetriminos(tetris_t *tetris)
{
    int *elems = get_sorted_list(tetris);

    for (int i = 0; i < tetris->num_tetri; i++)
        debug_reader(tetris, elems[i], i);
    free(elems);
}
