##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## minishell1
##

SRC	=	./main.c	\
		./src/my_putchar.c	\
		./src/my_putstr.c	\
		./src/my_strlen.c	\
		./src/my_strcmp.c	\
		./src/my_strcpy.c	\
		./src/my_printf.c	\
		./src/print_prompt.c	\
		./src/check_input.c	\
		./src/find_env.c	\
		./src/env_cmp.c	\
		./src/get_unsetenv.c	\
		./src/in_cd.c	\
		./src/def_env.c	\
		./src/my_strcat.c	\
		./src/my_isspace.c	\
		./src/get_setenv.c	\
		./lib/situ_spe.c	\
		./lib/situ_gene.c	\
		./lib/my_put_nbr.c	\
		./lib/my_pow.c		\
		./lib/get_float.c	\
		./lib/get_octal.c	\
		./lib/get_binary.c	\
		./lib/situx.c	\
		./lib/situ_x_mas.c	\
		./lib/res_dif_int.c

NAME	=	mysh

OBJ	=	$(wildcard *.o)

all:	$(NAME)

$(NAME):
	gcc -c -g3 $(SRC) -I./include 
	gcc -g3 -o $(NAME) *.o
	mkdir directory
	mv *.o directory/

clean:
	rm -rf directory/
	rm -f *.o
	rm -f src/*.o

re: 	fclean all

fclean: clean
	rm -f $(NAME)
