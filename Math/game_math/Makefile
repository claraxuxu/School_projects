##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_printf
##

SRC	=	101pong.c	

NAME	=	101pong

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):$(OBJ)
	gcc -o $(NAME) $(OBJ) -lm

clean:
	rm -f *.o

re: 	fclean all

fclean: clean
	rm -f $(NAME)
