/*
** EPITECH PROJET, 2019
** bsq
** File description:
** find the biggest square in file
*/

#include "include/my.h"

size_t get_size(char const *filepath)
{
    struct stat buf;

    if (stat(filepath,&buf) == 0)
        return (buf.st_size == 0 ? -1 : buf.st_size);
}
int readfile(int argc, char **argv, bsq_t *bsq)
{
    bsq->fd = open(argv[1],O_RDONLY);
    bsq->len = get_size(argv[1]);
    bsq->buf = malloc(sizeof(char) * bsq->len + 1);
    bsq->size = read(bsq->fd,bsq->buf,bsq->len);
    bsq->buf[bsq->size] = '\0';
    close(bsq->fd);
}
int put_answer(bsq_t bsq)
{
    for (int i = 0; i < bsq.row; i++) {
        my_putstr(bsq.matrix[i]);
        my_putchar('\n');
    }
}
int main(int argc, char **argv)
{
    bsq_t bsq;

    if (argc < 2)
        return (84);
    bsq.x = -1;
    bsq.y = -1;
    readfile(argc,argv,&bsq);
    if (bsq.fd < 0 || bsq.size < 0 || bsq.buf[0] == '\0')
        return (84);
    else {
        row_nums(&bsq);
        generatematrix(&bsq);
        maximalsquare(&bsq);
        if (bsq.x < 0 || bsq.y < 0)
            return (84);
        changematrix(&bsq);
        put_answer(bsq);
    }
}
