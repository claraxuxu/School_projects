/*
** EPITECH PROJECT, 2020
** extract_data.c
** File description:
** handles data extraction after call to API
*/

#include "lib.h"
#include "api_answer.h"
#include <stdlib.h>

float extract_float(data_t data)
{
    float *result = malloc(sizeof(float));

    *result = 0;
    if (data.format == THREE)
        result = (float *)data.data;
    return (*result);
}

float *extract_float_tab(data_t data)
{
    float *result = malloc(sizeof(float) * 32);

    for (int i = 0; i < 32; i++)
        result[i] = 0;
    if (data.format == TWO)
        result = copy_float_tab((float *)data.data);
    return (result);
}

vector_t extract_vector(data_t data)
{
    vector_t *result = malloc(sizeof(vector_t));

    result[0].x = 0;
    result[0].y = 0;
    if (data.format == FOUR)
        result = (vector_t *)data.data;
    return (*result);
}