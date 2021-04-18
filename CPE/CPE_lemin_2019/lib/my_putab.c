/*
** EPITECH PROJECT, 2019
** my_putab.c
** File description:
** Put tab
*/

char *my_putstr(char *str);

void my_putchar(char c);

int my_put_nbr(int nb);

void my_putab(char **tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
}

void my_put_map(char **tab)
{
    my_putstr(" |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_put_nbr(i + 1);
        my_putchar('|');
        for (int x = 0; x < 7; x++) {
            my_putchar(tab[i][x]);
            my_putchar(' ');
        }
        my_putchar(tab[i][7]);
        my_putchar('\n');
    }
}