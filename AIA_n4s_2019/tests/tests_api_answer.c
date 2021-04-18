/*
** EPITECH PROJECT, 2019
** tests_api_answer.c
** File description:
** testing api response protocol
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lib.h"
#include "loop.h"
#include "api_answer.h"
#include "structures.h"
#include <stddef.h>

Test(extract_float, extractfloat)
{
    float *fl = malloc(sizeof(float));
    data_t data = {
        .data = 0,
        .format = THREE
    };
    float asd;

    fl[0] = 12;
    data.data = (void *)fl;
    asd = extract_float(data);
    cr_assert_float_eq(asd, 12, 0);
    free(fl);
}

Test(extract_float_tab, extractfloattab)
{
    data_t data = {
        .data = 0,
        .format = TWO
    };
    float *asd = malloc(sizeof(float) * 32);
    float *tab;

    for (int i = 0; i < 32; i++)
        asd[i] = 0;
    data.data = (void *)asd;
    tab = extract_float_tab(data);
    for (int i = 0; i < 32; i++)
        cr_assert_float_eq(asd[i], tab[i], 0);
}

Test(extract_vector, extractvector)
{
    vector_t *vec = malloc(sizeof(vector_t));
    data_t data = {
        .data = 0,
        .format = FOUR
    };
    vector_t result = {0, 0};

    *vec = (vector_t){125, 32};
    data.data = (void *)vec;
    result = extract_vector(data);
    cr_assert_leq(result.x, vec->x);
    cr_assert_leq(result.y, vec->y);
}

Test(get_user_cmd, goodcmd)
{
    command_t cmd = get_user_cmd("stop");

    cr_assert_str_eq(cmd.command, "STOP_SIMULATION");
    cr_assert_str_eq(cmd.simplified_command, "stop");
    cr_assert_eq(cmd.expected_response, NONE);
    cr_assert_eq(cmd.value, ONE);
}

Test(get_user_cmd, badcmd)
{
    command_t cmd = get_user_cmd("soap");

    cr_assert_eq(cmd.command, 0);
    cr_assert_eq(cmd.simplified_command, 0);
    cr_assert_eq(cmd.value, NONE);
    cr_assert_eq(cmd.expected_response, NOFORMAT);
}

Test(get_user_cmd, nullcmd)
{
    char *asd = NULL;
    command_t cmd = get_user_cmd(asd);

    cr_assert_eq(cmd.command, 0);
    cr_assert_eq(cmd.simplified_command, 0);
    cr_assert_eq(cmd.value, NONE);
    cr_assert_eq(cmd.expected_response, NOFORMAT);
}

Test(init_answer_struct, initanswer)
{
    answer_t ans = init_answer_struct();

    cr_assert_eq(ans.is_ok, FALSE);
    cr_assert_eq(ans.code_verbose, 0);
    cr_assert_eq(ans.misc_info, INFO_ERROR);
}

Test(is_over, isnotover)
{
    answer_t ans = {
        .is_ok = FALSE,
        .code_verbose = my_strdup("very bad ! :("),
        .data.format = NOFORMAT,
        .misc_info = FIRSTCP_CLEARED,
        .value = 16
    };

    cr_assert_eq(is_over(ans), FALSE);
}

Test(get_vector, getvector)
{
    vector_t vec = get_vector(my_strdup("127, 12"));
    vector_t vec2 = get_vector("");

    cr_assert_leq(vec2.x, 0);
    cr_assert_leq(vec2.y, 0);
    cr_assert_leq(vec.x, 127);
    cr_assert_leq(vec.y, 12);
}

Test(get_additionnal_info, getaddinfo)
{
    cr_assert_eq(get_additionnal_info(my_strdup("shampoo")), INFO_ERROR);
    cr_assert_eq(get_additionnal_info(NULL), INFO_ERROR);
    cr_assert_eq(get_additionnal_info(my_strdup("First CP Cleared")),
    FIRSTCP_CLEARED);
    cr_assert_eq(get_additionnal_info(my_strdup("CP Cleared")), CP_CLEARED);
    cr_assert_eq(get_additionnal_info(my_strdup("Lap Cleared")), LAP_CLEARED);
    cr_assert_eq(get_additionnal_info(my_strdup("Track Cleared")),
    TRACK_CLEARED);
}