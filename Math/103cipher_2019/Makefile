##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_printf
##

SRC	=	103cipher.c	\
		./SRC/help.c	\
		./SRC/my_strlen.c	\
		./SRC/len.c	\
		./SRC/isnum.c	\
		./SRC/key_matrix.c	\
		./SRC/cipher_9.c	\
		./SRC/cipher_4.c	\
		./SRC/cipher_16.c	\
		./SRC/decrypt.c	\
		./SRC/check.c		\
		./SRC/get_matrix.c	\
		./SRC/get_code.c	\
		./SRC/get_sentence.c	\
		./SRC/get_result_mat.c

NAME	=	103cipher

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
