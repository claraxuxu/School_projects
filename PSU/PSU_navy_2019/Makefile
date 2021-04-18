##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## navy
##

########################
#####VARIABLES##########
########################

NAME	=	navy
CC		=	@gcc
CFLAGS	=   -g3
OBJ		=	$(wildcard *.o)

RED  	=  	"\e[31;1m"
GREEN 	= 	"\e[32;1m"
BLUE  	= 	"\e[34;1m"

########################
####FILES PATH##########
########################

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

RM		= 	@rm -rf

########################
#####COMPILATION########
########################

all:	$(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC) $(OUTILS) $(PRINT) -Iinclude 
	@$(CC) $(CFLAGS) -o $(NAME) *.o
	@mkdir objects/
	@mv *.o objects/
	@echo -e $(GREEN) "[*** COMPILATION NM SUCCEED ***]"

clean:
	@$(RM) $(NAME)
	@$(RM) objects/
	@$(RM) *.o
	@$(RM) src/*.o

re: 	fclean all

fclean: clean
	@echo -e $(BLUE) "[*** ALL CLEAN ***]"

########################
#####.PHONY#############
########################

.PHONY: all clean fclean re