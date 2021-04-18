/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** c file
*/

#include "../include/my.h"

char copybuf(char *res, char *buff, int count, int len)
{
    for (int j = 0; j < count; len++,j++)
        res[len] = buff[j];
    res[len] = '\0';
}
char *get_line(char *line, int count, char *buff, int *i)
{
    char *res;
    int len = 0;

    if (line != NULL)
        for (; line[len] != 0; len++);
    res = malloc(sizeof(char) * (len + READ_SIZE + 1));
    my_strncpy(res,line,len);
    copybuf(res,buff,count,len);
    *i += count + 1;
    return (res);
}
char *stock_line(char *line, int count, char *buff, int *i)
{
    char *res;
    char *buf = malloc(sizeof(char) * READ_SIZE + 1);
    int len = 0;

    if (line != 0)
        for (; line[len] != 0; len++);
    res = malloc(sizeof(char) * (len + READ_SIZE + 1));
    if (line != 0)
        my_strncpy(res,line,len);
    for (int k = (*i),j = 0; buff[k] != '\0'; k++,j++)
        buf[j] = buff[k];
    copybuf(res,buf,count,len);
    *i += count + 1;
    line = res;
}
int check_fd(int fd, int size)
{
    if (fd < 0 || size < 0)
        return (0);
    if (size == 0)
        return (3);
}
char *get_next_line(int fd)
{
    static char buf[READ_SIZE];
    char *line = NULL;
    static int size = 0;
    static int i = 0;
    int count = 0;

    while (buf != NULL) {
        if (size == 0 || size <= i) {
            i = count = 0;
            size = read(fd,buf,READ_SIZE);
            if (check_fd(fd,size) == 3)
                return (line);
        }
        if (buf[i + count] == '\n')
            return (get_line(line,count,buf,&i));
        count++;
        if (i + count == size)
            line = stock_line(line,count,buf,&i);
    }
}
