/*
** EPITECH PROJECT, 2019
** tests_answer_type.c
** File description:
** testing api answer extraction
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lib.h"
#include "loop.h"
#include "api_answer.h"
#include "structures.h"
#include <stddef.h>

Test(format_one, format_one_extraction)
{
    answer_t ans = format_one("3:OK:This is a test:First CP Cleared");

    cr_assert_eq(ans.value, 3);
    cr_assert_eq(ans.is_ok, TRUE);
    cr_assert_eq(ans.data.format, ONE);
    cr_assert_str_eq(ans.code_verbose, "This is a test");
    cr_assert_eq(ans.misc_info, FIRSTCP_CLEARED);
}

Test(format_three, format_three_extraction)
{
    answer_t ans = format_three("3:OK:This is a test:5.2:First CP Cleared");
    float result;

    cr_assert_eq(ans.value, 3);
    cr_assert_eq(ans.is_ok, TRUE);
    cr_assert_eq(ans.data.format, THREE);
    cr_assert_str_eq(ans.code_verbose, "This is a test");
    cr_assert_eq(ans.misc_info, FIRSTCP_CLEARED);
    result = extract_float(ans.data);
    cr_assert_float_eq(result, 5.2, 0.5);
}

Test(format_four, format_four_extraction)
{
    answer_t ans = format_four("6:OK:test:5, 2:First CP Cleared");
    vector_t vec;

    cr_assert_eq(ans.value, 6);
    cr_assert_eq(ans.is_ok, TRUE);
    cr_assert_eq(ans.data.format, FOUR);
    cr_assert_str_eq(ans.code_verbose, "test");
    cr_assert_eq(ans.misc_info, FIRSTCP_CLEARED);
    vec = extract_vector(ans.data);
    cr_assert_eq(vec.x, 5);
    cr_assert_eq(vec.y, 2);
}

Test(get_answer_type, testswitchcase_err)
{
    format_t format = API_ERROR;
    char *str = my_strdup("this is wrong !");
    answer_t def = init_answer_struct();
    answer_t res = get_answer_type(str, format);

    cr_assert_eq(def.data.format, res.data.format);
    cr_assert_eq(def.code_verbose, res.code_verbose);
    cr_assert_eq(def.misc_info, res.misc_info);
    cr_assert_eq(def.is_ok, res.is_ok);
    cr_assert_eq(def.value, res.value);
}

Test(get_answer_type, testswitchcase_one)
{
    format_t format = ONE;
    char *str = my_strdup("3:OK:This is a test:First CP Cleared");
    answer_t def = format_one(str);
    answer_t res = get_answer_type(str, format);

    cr_assert_eq(def.data.format, res.data.format);
    cr_assert_str_eq(def.code_verbose, res.code_verbose);
    cr_assert_eq(def.misc_info, res.misc_info);
    cr_assert_eq(def.is_ok, res.is_ok);
    cr_assert_eq(def.value, res.value);
}

Test(get_answer_type, testswitchcase_two)
{
    format_t format = TWO;
    char *str = my_strdup("3:OK:This is a test:5.23:First CP Cleared");
    answer_t def = format_two(str);
    answer_t res = get_answer_type(str, format);

    cr_assert_eq(def.data.format, res.data.format);
    cr_assert_str_eq(def.code_verbose, res.code_verbose);
    cr_assert_eq(def.misc_info, res.misc_info);
    cr_assert_eq(def.is_ok, res.is_ok);
    cr_assert_eq(def.value, res.value);
}

Test(get_answer_type, testswitchcase_three)
{
    format_t format = THREE;
    char *str = my_strdup("3:OK:This is a test:5.2:First CP Cleared");
    answer_t def = format_three(str);
    answer_t res = get_answer_type(str, format);

    cr_assert_eq(def.data.format, res.data.format);
    cr_assert_str_eq(def.code_verbose, res.code_verbose);
    cr_assert_eq(def.misc_info, res.misc_info);
    cr_assert_eq(def.is_ok, res.is_ok);
    cr_assert_eq(def.value, res.value);
}

Test(get_answer_type, testswitchcase_four)
{
    format_t format = FOUR;
    char *str = my_strdup("6:OK:test:5, 2:First CP Cleared");
    answer_t def = format_four(str);
    answer_t res = get_answer_type(str, format);

    cr_assert_eq(def.data.format, res.data.format);
    cr_assert_str_eq(def.code_verbose, res.code_verbose);
    cr_assert_eq(def.misc_info, res.misc_info);
    cr_assert_eq(def.is_ok, res.is_ok);
    cr_assert_eq(def.value, res.value);
}

Test(get_answer_type, testswitchcase_none)
{
    format_t format = API_ERROR;
    char *str = my_strdup("this is wrong !");
    answer_t def = init_answer_struct();
    answer_t res = get_answer_type(str, format);

    cr_assert_eq(def.data.format, res.data.format);
    cr_assert_eq(def.code_verbose, res.code_verbose);
    cr_assert_eq(def.misc_info, res.misc_info);
    cr_assert_eq(def.is_ok, res.is_ok);
    cr_assert_eq(def.value, res.value);
}