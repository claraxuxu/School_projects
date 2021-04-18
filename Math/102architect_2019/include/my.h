/*
** EPITECH PROJECT, 2019
** header file
** File description:
** prototypes of all the functions in lib
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define PI_DIV_180 (0.0174532)
#define DegToRad(x)	((x) * PI_DIV_180)

int help();
int translation(char **av);
int scaling(char **av);
int rotation(char **av);
int reflection(char **av);
