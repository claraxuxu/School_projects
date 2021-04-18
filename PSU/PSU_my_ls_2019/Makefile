##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_ls
##

########################
#####VARIABLES##########
########################

NAME	=	my_ls
CC		=	@gcc
CFLAGS	=   -g3
OBJ		=	$(wildcard *.o)

RED  	=  	"\e[31;1m"
GREEN 	= 	"\e[32;1m"
BLUE  	= 	"\e[34;1m"

########################
####FILES PATH##########
########################

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
		./lib/my/get_hex.c	\
		./lib/my/put_res_part.c

RM		= 	@rm -rf

########################
#####COMPILATION########
########################

all:	$(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC) -I./include 
	@$(CC) $(CFLAGS) -o $(NAME) *.o -lncurses
	@mkdir objects/
	@mv *.o objects/
	@echo -e $(GREEN) "[*** COMPILATION NM SUCCEED ***]"

clean:
	@$(RM) $(NAME)
	@$(RM) objects/
	@$(RM) *.o
	@$(RM) src/*.o

re: fclean all

fclean: clean
	@echo -e $(BLUE) "[*** ALL CLEAN ***]"

########################
#####.PHONY#############
########################

.PHONY: all clean fclean re