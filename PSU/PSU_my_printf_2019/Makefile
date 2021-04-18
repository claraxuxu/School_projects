##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_printf
##

########################
#####VARIABLES##########
########################

NAME	=	my_printf
CC		=	@gcc
CFLAGS	=   -g3
OBJ		=	$(wildcard *.o)

RED  	=  	"\e[31;1m"
GREEN 	= 	"\e[32;1m"
BLUE  	= 	"\e[34;1m"

########################
####FILES PATH##########
########################

SRC	=	my_printf.c	\
		lib/*.c

# OBJ	=	$(SRC:.c=.o)

RM		= 	@rm -rf

########################
#####COMPILATION########
########################

all:	$(NAME)

$(NAME):$(OBJ)
	@$(CC) $(CFLAGS) -c $(SRC) -Iinclude
	@$(CC) $(CFLAGS) -o $(NAME) *.o -Ofast
	@mkdir objects/
	@mv *.o objects/
	@echo -e $(GREEN) "[*** COMPILATION NM SUCCEED ***]"

clean:
	@$(RM) $(NAME)
	@$(RM) objects/
	@$(RM) *.o
	@$(RM) lib/*.o

re: 	fclean all

fclean: clean
	@echo -e $(BLUE) "[*** ALL CLEAN ***]"

########################
#####.PHONY#############
########################

.PHONY: all clean fclean re