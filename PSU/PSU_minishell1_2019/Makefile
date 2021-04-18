##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## minishell1
##

########################
#####VARIABLES##########
########################

NAME	=	mysh
CC		=	@gcc
CFLAGS	=   -g3
OBJ		=	$(wildcard *.o)

RED  	=  	"\e[31;1m"
GREEN 	= 	"\e[32;1m"
BLUE  	= 	"\e[34;1m"

########################
####FILES PATH##########
########################

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

RM		= 	@rm -rf

########################
#####COMPILATION########
########################

all:	$(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC) -I./include 
	@$(CC) $(CFLAGS) -o $(NAME) *.o
	@mkdir objects/
	@mv *.o objects/
	@echo -e $(GREEN) "[*** COMPILATION NM SUCCEED ***]"

clean:
	@$(RM) $(NAME)
	@$(RM) objects/
	@$(RM) directory/
	@$(RM) *.o
	@$(RM) src/*.o

re: fclean all

fclean: clean
	@echo -e $(BLUE) "[*** ALL CLEAN ***]"

########################
#####.PHONY#############
########################

.PHONY: all clean fclean re