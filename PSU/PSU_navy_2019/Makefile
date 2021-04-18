##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## navy
##

NAME	=	navy

SRC	=	./main.c					\
		./fonc_base/my_put.c		\
		./fonc_base/my_strlen.c		\
		./fonc_base/my_getnbr.c		\
		./fonc_base/my_atoi.c		\
		./fonc_base/my_strncpy.c	\
		./fonc_base/my_str_is.c		\
		./fonc_base/my_printf.c

PRINT 	= 	./fonc_base/lib/situ_gene.c		\
			./fonc_base/lib/my_pow.c		\
			./fonc_base/lib/get_binary.c	\
			./fonc_base/lib/res_dif_int.c
	
OUTILS	=	./docs/help_part.c			\
			./docs/put_map.c			\
			./docs/get_answer.c			\
			./docs/make_connection.c	\
			./docs/process.c			\
			./docs/game.c				\
			./docs/receive_answer.c		\
			./docs/build/read_file.c	\
			./docs/build/build_tab.c	\
			./docs/build/build_map.c	\
			./docs/check/check_map.c	\
			./docs/check/check_attack.c	\
			./docs/check/check_win.c



OBJ	=	$(wildcard *.o)

all:	$(NAME)

$(NAME):
		gcc -c -g3 $(SRC) $(OUTILS) $(PRINT) -Iinclude 
		gcc -g3 -o $(NAME) *.o

clean:
		rm -f *.o
		rm -f src/*.o

re: 	fclean all

fclean: clean
	rm -f $(NAME)
