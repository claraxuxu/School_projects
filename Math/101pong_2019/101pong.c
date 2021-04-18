/*
** EPITECH PROJECT, 2019
** 101pong
** File description:
** two positions of vector given and get result of next
** cos = z(difference of z0 and z1) / ||velcocity vctor of ball||
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

void help_part()
{
    printf("USAGE\n");
    printf("    ./101pong x0 y0 z0 x1 y1 z1 n \n\n");
    printf("DESCRIPTION\n");
    printf("    x0  ball abscissa at time t - 1\n");
    printf("    y0  ball ordinate at time t - 1\n");
    printf("    z0  ball altitude at time t - 1\n");
    printf("    x1  ball abscissa at time t\n");
    printf("    y1  ball ordinate at time t\n");
    printf("    z1  ball altitude at time t\n");
    printf("    n   time shift (greater than or equal to zero, integer)\n");
}

void touch_paddle(float x, float y,float z)
{
    float base = x * x + y * y + z * z;
    float res_cos = acos(z / pow(base,0.5));
    float res = ((res_cos - PI / 2) * 180) / PI;

    printf("The incidence angle is:\n%.2f degrees\n",res);
}

void pong(char **av)
{
    float x = atof(av[4]) - atof(av[1]);
    float y = atof(av[5]) - atof(av[2]);
    float z = atof(av[6]) - atof(av[3]);
    float n = atof(av[7]);
    float res_x = atof(av[4]) + x * n;
    float res_y = atof(av[5]) + y * n;
    float res_z = atof(av[6]) + z * n;

    printf("The velocity vector of the ball is:\n");
    printf("(%.2f, %.2f, %.2f)\n",x,y,z);
    printf("At time t + %.0f, ball coordinates will be:\n",n);
    printf("(%.2f, %.2f, %.2f)\n",res_x,res_y,res_z);
    if (atof(av[6]) * res_z < 0)
        touch_paddle(x,y,z);
    else
        printf("The ball won't reach the paddle.\n");
}

int isnum(char **av)
{
    int test = 0;

    for (int i = 1; i<= 7; i++) {
        if ((av[i][0] >= '0' && av[i][0] <= '9') ||
            (av[i][0] == '-' && av[i][1] >= '0' && av[i][1] <= '9'))
                test++;
        }
    return (test);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        help_part();
    else if (ac == 8 && atoi(av[7]) >= 0 && atoi(av[7]) == atof(av[7])) {
        if (isnum(av) == 7)
            pong(av);
        else
            return (84);
    }
    else
        return (84);
    return (0);
}
