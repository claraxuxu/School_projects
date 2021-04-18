/*
** EPITECH PROJECT, 2019
** unit_test
** File description:
** unit test for get_next_line
*/

#include  <criterion/criterion.h>
#include  <criterion/redirect.h>
#include  <fcntl.h>
#include  <unistd.h>

char *get_next_line(int fd);
int fd =  -1;

void  open_file(void)
{
    fd = open("txt", O_RDONLY);
    cr_redirect_stdout ();
}
void  close_file(void)
{
    if (fd !=  -1)
        close(fd);
}
Test(get_next_line , read_line , .init = open_file , .fini = close_file)
{
    char *expected = "I dont know what to say.";
    char *got = get_next_line(fd);
    cr_assert_str_eq(got , expected);
}