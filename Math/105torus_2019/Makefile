##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 105torus
##

SRC	=	./105torus.c	\
		./SRC/help.c	\
		./SRC/my_strlen.c	\
		./SRC/my_str_isnum.c	\
		./SRC/change_to_num.c	\
		./SRC/disec_metho.c	\
		./SRC/newton_metho.c	\
		./SRC/secant_metho.c

NAME	=	105torus

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
