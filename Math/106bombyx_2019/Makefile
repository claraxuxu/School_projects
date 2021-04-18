##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 106bombyx
##

SRC	=	./main.c	\
		./SRC/help.c	\
		./SRC/my_strlen.c	\
		./SRC/my_str_isnum.c	\
		./SRC/my_num.c	\
		./SRC/first_check.c	\
		./SRC/second_check.c

NAME	=	106bombyx

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
