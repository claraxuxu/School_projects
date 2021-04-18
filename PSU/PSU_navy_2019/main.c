/*
** EPITECH PROJECT, 2019
** main
** File description:
** main file for navy
*/

#include "my.h"

void init(int ac, file_t *file)
{
    file->turn = 1;
    file->ac = ac;
    file->status = 0;
    file->win = 0;
    file->exit = 0;
}
int prepare_game(char **av, file_t *file)
{
    if (av[1][0] == '-' && av[1][1] == 'h')
        help_part();
    if (read_file(av[file->ac - 1], file) == -1)
        return (-1);
    if (make_connection(file,av) == -1)
        return (-1);
    return (0);
}
int main(int ac, char **av)
{
    file_t file;
    init(ac, &file);
    if ((ac != 3 && ac != 2) || (ac == 3 && my_str_isnump(av[1]) == 0))
        return (84);
    if (open(av[ac - 1], O_RDONLY) == -1)
        return (84);
    if (prepare_game(av, &file) == -1) return (84);
    put_map(&file);
    id2 = 0;
    while (1) {
        if (process(&file) == 1)
            break;
        if (file.exit == 1 || file.win > 0)
            break;
    }
    return (0);
}