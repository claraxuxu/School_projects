##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_sokoban
##

SRC	=	./my_sokoban.c	\
		./SRC/my_putchar.c	\
		./SRC/my_putstr.c	\
		./SRC/my_strlen.c	\
		./SRC/my_put_nbr.c	\
		./SRC/help.c		\
		./SRC/check_error.c	\
		./SRC/check_o.c		\
		./SRC/check_win.c	\
		./SRC/up_down.c		\
		./SRC/count_buf.c	\
		./SRC/direction.c	\
		./SRC/get_pos.c


NAME	=	my_sokoban

OBJ	=	$(wildcard *.o)

NAME2	=	libmy.a

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):
	gcc -c -g3 $(SRC) -I./include 
	gcc -g3 -o $(NAME) *.o -lncurses

clean:
	rm -f *.o
	rm -f SRC/*.o

re: 	fclean all

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)
