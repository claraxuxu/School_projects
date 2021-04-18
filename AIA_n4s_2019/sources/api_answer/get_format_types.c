/*
** EPITECH PROJECT, 2020
** get_format_types.c
** File description:
** get specific parts of the API's reponse
*/

#include <string.h>
#include "api_answer.h"
#include "lib.h"
#include <stdlib.h>

additional_info_t get_additionnal_info(char *s)
{
    if (s == NULL || s[0] == 0)
        return INFO_ERROR;
    if (strncmp("First CP Cleared", s, my_strlen("First CP Cleared")) == 0)
        return FIRSTCP_CLEARED;
    if (strncmp("CP Cleared", s, my_strlen("CP Cleared")) == 0)
        return CP_CLEARED;
    if (strncmp("Lap Cleared", s, my_strlen("Lap Cleared")) == 0)
        return LAP_CLEARED;
    if (strncmp("Track Cleared", s, my_strlen("Track Cleared")) == 0)
        return TRACK_CLEARED;
    return INFO_ERROR;
}

float *copy_float_tab(float *tab)
{
    float *result = malloc(sizeof(float) * 33);

    for (int i = 0; i <= 31; i++)
        result[i] = tab[i];
    result[32] = -9999;
    return (result);
}

static bool_t is_float(char const *string)
{
    if (string == NULL || string[0] == 0)
        return FALSE;
    for (int i = 0; string[i] != 0; i++) {
        if ((string[i] < '0' || string[i] > '9') && string[i] != '.' &&
        string[i] != '-')
            return FALSE;
    }
    return TRUE;
}

float *get_float_tab(char **input, int *size)
{
    float *result = malloc(sizeof(float) * 32);
    int i = 0;

    for (; input[i] != NULL; i++) {
        if (!is_float(input[i]))
            break;
        else result[i] = atof(input[i]);
    }
    i = *size;
    return (result);
}

vector_t get_vector(char *s)
{
    vector_t result = {
        .x = 0,
        .y = 0
    };

    if (s == NULL || s[0] == 0)
        return result;
    result.x = atol(copy_until(s, ',', 0));
    result.y = atol(get_last_occurence_of(s, ','));
    return (result);
}