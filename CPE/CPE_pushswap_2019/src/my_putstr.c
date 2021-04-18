/*
** EPITECH PROJECT, 2019
** my_putstrc
** File description:
** for day07
*/
void my_putchar(char c);

void my_putstr(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
