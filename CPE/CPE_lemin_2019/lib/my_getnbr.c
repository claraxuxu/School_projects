/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** my_getnbr
*/

int my_getnbr(char *str)
{
    int	i;
    int	nb;

    i = 0;
    nb = 0;
    if (str[0] == '-' && str[1] != '\0')
        i++;
    while (str[i] != '\0') {
        nb += str[i] - 48;
        nb *= 10;
        i++;
    }
    nb /= 10;
    if (str[0] == '-')
        return (-1 * nb);
    else
        return (nb);
}