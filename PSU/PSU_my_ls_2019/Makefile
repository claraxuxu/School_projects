##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_ls
##

SRC	=	./my_ls.c	\
		./src/my_strcpy.c	\
		./src/my_putchar.c	\
		./src/my_putstr.c	\
		./src/my_strlen.c	\
		./src/my_strcat.c	\
		./src/git_to_name.c	\
		./src/my_itoa.c	\
		./src/uid_to_name.c	\
		./src/mode_to_letters.c	\
		./src/show_file_info.c	\
		./src/check.c	\
		./src/analyze.c	\
		./src/do_ls.c	\
		./lib/my/my_printf.c	\
		./lib/my/situ_spe.c	\
		./lib/my/situ_gene.c	\
		./lib/my/my_put_nbr.c	\
		./lib/my/my_put_usnbr.c	\
		./lib/my/my_pow.c		\
		./lib/my/get_float.c	\
		./lib/my/get_octal.c	\
		./lib/my/get_binary.c	\
		./lib/my/situx.c	\
		./lib/my/situ_x_mas.c	\
		./lib/my/res_dif_int.c	\
		./lib/my/get_hex.c

NAME	=	my_ls

OBJ	=	$(wildcard *.o)

all:	$(NAME)

$(NAME):
	gcc -c -g3 $(SRC) -I./include 
	gcc -g3 -o $(NAME) *.o -lncurses

clean:
	rm -f *.o
	rm -f src/*.o

re: 	fclean all

fclean: clean
	rm -f $(NAME)
