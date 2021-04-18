##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_sokoban
##

########################
#####VARIABLES##########
########################

NAME	=	my_sokoban
CC		=	@gcc
CFLAGS	=   -g3
OBJ		=	$(wildcard *.o)

RED  	=  	"\e[31;1m"
GREEN 	= 	"\e[32;1m"
BLUE  	= 	"\e[34;1m"

########################
####FILES PATH##########
########################

SRC	=	./my_sokoban.c	\
		./SRC/my_putchar.c	\
		./SRC/my_putstr.c	\
		./SRC/my_strlen.c	\
		./SRC/my_put_nbr.c	\
		./SRC/help.c		\
		./SRC/check_error.c	\
		./SRC/check_o.c		\
		./SRC/check_win.c	\
		./SRC/up_down.c		\
		./SRC/count_buf.c	\
		./SRC/direction.c	\
		./SRC/get_pos.c

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
	@$(RM) SRC/*.o

re: 	fclean all

fclean: clean
	@echo -e $(BLUE) "[*** ALL CLEAN ***]"

########################
#####.PHONY#############
########################

.PHONY: all clean fclean re