/*
** EPITECH PROJECT, 2020
** get_answer_type.c
** File description:
** handles buffer splitting and redistribution into struct
*/

#include "api_answer.h"
#include "lib.h"
#include <stdlib.h>
#include "macros.h"

answer_t format_one(char *buffer)
{
    answer_t ans = init_answer_struct();
    char **tab = tabgen(buffer, ':');

    ans.value = my_getnbr(tab[0]);
    ans.is_ok = my_strcmp(tab[1], "OK") == 0 ? TRUE : FALSE;
    ans.code_verbose = my_strdup(tab[2]);
    ans.misc_info = get_additionnal_info(tab[3]);
    ans.data.format = ONE;
    ans.data.data = NULL;
    free_tab((void **)tab);
    return (ans);
}

answer_t format_two(char *buffer)
{
    answer_t ans = init_answer_struct();
    char **tab = tabgen(buffer, ':');
    float *info = NULL;
    int i = 0;

    ans.value = my_getnbr(tab[0]);
    ans.is_ok = my_strcmp(tab[1], "OK") == 0 ? TRUE : FALSE;
    ans.code_verbose = my_strdup(tab[2]);
    info = get_float_tab(&tab[3], &i);
    ans.data.format = TWO;
    ans.data.data = ((void *)copy_float_tab(info));
    ans.misc_info = get_additionnal_info(tab[i]);
    free_tab((void **)tab);
    FREE(info);
    return (ans);
}

answer_t format_three(char *buffer)
{
    answer_t ans = init_answer_struct();
    char **tab = tabgen(buffer, ':');
    float *info = malloc(sizeof(float));

    ans.value = my_getnbr(tab[0]);
    ans.is_ok = my_strcmp(tab[1], "OK") == 0 ? TRUE : FALSE;
    ans.code_verbose = my_strdup(tab[2]);
    info[0] = atof(tab[3]);
    ans.data.format = THREE;
    ans.data.data = (void *)info;
    ans.misc_info = get_additionnal_info(tab[4]);
    free_tab((void **)tab);
    return (ans);
}

answer_t format_four(char *buffer)
{
    answer_t ans = init_answer_struct();
    char **tab = tabgen(buffer, ':');
    vector_t *info = malloc(sizeof(vector_t));

    ans.value = my_getnbr(tab[0]);
    ans.is_ok = my_strcmp(tab[1], "OK") == 0 ? TRUE : FALSE;
    ans.code_verbose = my_strdup(tab[2]);
    info[0] = get_vector(tab[3]);
    ans.data.format = FOUR;
    ans.data.data = (void *)info;
    ans.misc_info = get_additionnal_info(tab[4]);
    free_tab((void **)tab);
    return (ans);
}

answer_t get_answer_type(char *answer, format_t format)
{
    switch (format) {
        case API_ERROR:
            return (init_answer_struct());
        case ONE:
            return (format_one(answer));
        case TWO:
            return (format_two(answer));
        case THREE:
            return (format_three(answer));
        case FOUR:
            return (format_four(answer));
        default:
            break;
    }
    return (init_answer_struct());
}