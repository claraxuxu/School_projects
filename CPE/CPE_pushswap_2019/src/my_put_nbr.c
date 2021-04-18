/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** display the number given as a parameter
*/

void my_putchar(char c);

int special(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int nb)
{
    int n = 0;

    if (nb == -2147483648) {
        special();
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        n = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(n + 48);
    } else {
        my_putchar(nb + 48);
    }
    return (0);
}
