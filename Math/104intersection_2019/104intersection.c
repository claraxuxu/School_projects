/*
** EPITECH PROJECT, 2019
** 104intersection
** File description:
** 
*/

#include "include/my.h"

int put_sphere(num_t *num, char **av)
{
    num->a = pow(num->xv,2) + pow(num->yv,2) + pow(num->zv,2);
    num->b = 2 * (num->xp * num->xv + num->yp * num->yv + num->zp * num->zv);
    num->c = pow(num->xp,2) + pow(num->yp,2) + pow(num->zp,2) - pow(num->p,2);
    num->del = pow(num->b,2) - (4 * num->a * num->c);
    printf("Sphere of radius %s\n",av[8]);
    printf("Line passing through the point (%s, %s, %s)",av[2],av[3],av[4]);
    printf(" and parallel to the vector (%s, %s, %s)\n",av[5],av[6],av[7]);
    sphere(num);
}
int put_cylinder(num_t *num, char **av)
{
    num->a = pow(num->xv,2) + pow(num->yv,2);
    num->b = (2 * num->xp * num->xv) + (2 * num->yp * num->yv);
    num->c = pow(num->xp,2) + pow(num->yp,2) - pow(num->p,2);
    num->del = pow(num->b,2) - (4 * num->a * num->c);
    printf("Cylinder of radius %s\n",av[8]);
    printf("Line passing through the point (%s, %s, %s)",av[2],av[3],av[4]);
    printf(" and parallel to the vector (%s, %s, %s)\n",av[5],av[6],av[7]);
    cylinder(num);
}
int put_cone(num_t *num, char **av)
{
    num->t = tan(num->p);
    num->a = pow(num->xv,2) + pow(num->yv,2) - pow(num->zv,2) * pow(num->t,2);
    num->b = 2 * num->xp * num->xv + 2 * num->yp * num->yv - (2 * num->zp * 
            num->zv * pow(num->t,2));
    num->c = pow(num->xp,2) + pow(num->yp,2) - pow(num->zp,2) * pow(num->t,2);
    num->del = pow(num->b,2) - (4 * num->a * num->c);
    printf("cone with a %s degree angle\n",av[8]);
    printf("Line passing through the point (%s, %s, %s)",av[2],av[3],av[4]);
    printf(" and parallel to the vector (%s, %s, %s)\n",av[5],av[6],av[7]);
    cone(num);
}
int dif_situ(char **av)
{
    num_t num;

    change_to_num(&num,av);
    if (av[1][0] == '1' && av[1][1] == '\0')
        put_sphere(&num,av);
    else if (av[1][0] == '2' && av[1][1] == '\0')
        put_cylinder(&num,av);
    else if (av[1][0] == '3' && av[1][1] == '\0')
        put_cone(&num,av);
    else
        exit (84);
}
int main(int ac, char **av)
{
    if (ac == 9 && isnum(ac,av) >= 8)
        dif_situ(av);
    else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        help();
    else
        exit (84);
    return (0);
}
