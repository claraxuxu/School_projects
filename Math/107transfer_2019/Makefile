##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 106bombyx
##

SRC	=	./main.c	\
		./SRC/my_strdup.c	\
		./SRC/help.c	\
		./SRC/my_str_isnum.c	\
		./SRC/check.c	\
		./SRC/my_strlen.c	\
		./SRC/progress.c

NAME	=	107transfer

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
