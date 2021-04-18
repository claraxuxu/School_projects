##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_printf
##

SRC	=	my_printf.c	\
		lib/*.c

NAME	=	my_printf


OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):$(OBJ)
	gcc -c -g3 $(SRC) -Iinclude
	gcc -g3 -o $(NAME) *.o -Ofast
	mkdir binary
	mv *.o binary/

clean:
	rm -rf binary/
	rm -f *.o
	rm -f lib/*.o

re: 	fclean all

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)
