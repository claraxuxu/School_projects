/*
** EPITECH PROJECT, 2019
** my_strcapitalize.c
** File description:
** task01
*/

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    return (str);
}
