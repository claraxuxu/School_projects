/*
** EPITECH PROJECT, 2019
** build_tab
** File description:
** make blank map
*/

#include "my.h"

int check_tab_continue(int tab[4][6], int i, int size)
{
    if (tab[i][2] == tab[i][4])
        if ((tab[i][3] - tab[i][1] + 1) != size)
            return (-1);
    if ((tab[i][1] != tab[i][3]) && (tab[i][2] != tab[i][4]))
        return (-1);
    return (0);
}
int check_tab(int tab[4][6])
{
    int size = 0;

    for (int i = 0; i < 4; i++) {
        size = i + 2;
        if (tab[i][0] != size)
            return (-1);
        if (tab[i][1] == tab[i][3])
            if ((tab[i][4] - tab[i][2] + 1) != size)
                return (-1);
        if (check_tab_continue(tab, i, size) == -1)
            return (-1);
    }
}
int change_to_num(file_t *file, int i, int j, int k)
{
    if (my_str_isalpha(file->buf[i]) == 1)
        if ((file->tab[j][k] = my_atoi(file->buf[i] - 16)) > 8) 
            return (-1);
    if (my_str_isnum(file->buf[i]) == 1)
        if ((file->tab[j][k] = my_atoi(file->buf[i])) > 8)
            return (-1);
    return (0);
}
int build_tab(file_t *file)
{
    int count = 0;
    
    for (int i = 0, j = 0, k = 0; file->buf[i] != '\0'; i++,k++) {
        if (file->buf[i] == '\n') {
            file->tab[j][k] = '\0';
            j++;
            i++;
            k = 0;
        }
        if (file->buf[i] == ':') {
            count++;
            i++;
        }
        if (change_to_num(file, i, j, k) == -1)
            return (-1);
    }
    if (count != 8) return (-1);
    if (check_tab(file->tab) == -1) return (-1);
    build_map(file);
}
