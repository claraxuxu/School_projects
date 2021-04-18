/*
** EPITECH PROJECT, 2019
** help
** File description:
** for 102architect help part
*/

int help()
{
    printf("USAGE\n");
    printf("    ./102achitect x y transfo1 arg11 [arg12] ");
    printf("[transfo2 arg12 [arg22]] ...\nDESCRIPTION\n");
    printf("    x  abscissa of the original point\n");
    printf("    y  ordinate of the original point\n\n");
    printf("    transfo arg1 [arg2]\n");
    printf("    -t i j  translationa along vector (i, j)\n");
    printf("    -z m n  scaling by factor m (s-axis) and n (y-axis)\n");
    printf("    -r d    rotation centered in 0 by a d degree angle\n");
    printf("    -s d    reflection over the axis passing through 0 ");
    printf("with an inclination\n");
    printf("            angle of d degrees\n");
}