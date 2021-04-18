/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** my_sort_params.c
*/

int my_comp(char *s1, char *s2)
{
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i] || s1[i + 1] != '\0' || s2[i] != '\0')
            return (s1[i] - s2[i]);
    }
    return 0;
}

void my_swap(char **s1, char **s2)
{
    char *tmp = *s1;

    *s1 = *s2;
    *s2 = tmp;
}

void my_sort_params(char **tab, int max)
{
    int ok = 1;

    for (int i = 0; i < max - 1 && ok == 1; i++) {
        ok = 0;
        for (int j = 0; j < max - 1; j++)
            if (my_comp(tab[j], tab[j + 1]) > 0) {
                my_swap(&tab[j], &tab[j + 1]);
                ok = 1;
            }
    }
}