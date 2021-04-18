##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_printf
##

SRC	=	104intersection.c	\
		./SRC/help.c	\
		./SRC/my_strlen.c	\
		./SRC/isnum.c	\
		./SRC/change_to_num.c	\
		./SRC/sphere.c	\
		./SRC/cylinder.c	\
		./SRC/cone.c

NAME	=	104intersection

NAME2	=	libmy.a

OBJ	=	$(wildcard *.o)

all:	$(NAME)

$(NAME):
	gcc -c -g3 $(SRC) -I./include -Ofast
	gcc -g3 -o $(NAME) *.o -lm

clean:
	rm -f *.o
	rm -f SRC/*.o

re: 	fclean all

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)
