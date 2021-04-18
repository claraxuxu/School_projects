##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_printf
##

########################
#####VARIABLES##########
########################

NAME	=	bsq
NAME2	=	libmy.a
CC		=	@gcc
CFLAGS	=   -Wall -Wextra -g3 -Ofast
OBJ	=	$(wildcard *.o)

RED  	=  	"\e[31;1m"
GREEN 	= 	"\e[32;1m"
BLUE  	= 	"\e[34;1m"

########################
####FILES PATH##########
########################

SRC	=	./bsq.c	\
		./lib/my_putchar.c	\
		./lib/my_strlen.c	\
		./lib/my_putstr.c	\
		./lib/row_num.c	\
		./lib/generatematrix.c	\
		./lib/maximalsquare.c	\
		./lib/changematrix.c

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
	@$(RM) $(NAME2)
	@$(RM) objects/
	@$(RM) *.o
	@$(RM) lib/my/*.o

re: 	fclean all

fclean: clean
	@echo -e $(BLUE) "[*** ALL CLEAN ***]"

########################
#####.PHONY#############
########################

.PHONY: all clean fclean re