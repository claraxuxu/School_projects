##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_printf
##

SRC	=	102architect.c	\
		SRC/help.c		\
		SRC/translation.c	\
		SRC/scaling.c	\
		SRC/rotation.c	\
		SRC/reflection.c
		

NAME	=	102architect

NAME2	=	libmy.a

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME2) $(OBJ)
	gcc -g3 -o $(NAME) $(OBJ) -L. -lmy -lm

clean:
	rm -f *.o
	rm -f SRC/*.o

re: 	fclean all

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)
