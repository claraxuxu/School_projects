##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## dante generator
##

########################
#####VARIABLES##########
########################

NAME	=	generator
CC		=	@gcc
CFLAGS	=   -Wall -Wextra -g3 -Ofast
OBJ	=	$(wildcard *.o)

RED  	=  	"\e[31;1m"
GREEN 	= 	"\e[32;1m"
BLUE  	= 	"\e[34;1m"

########################
####FILES PATH##########
########################

SRC	=	./main.c	\
		./../outils/src/my_put.c	\
		./../outils/src/my_strlen.c	\
		./../outils/src/my_getnbr.c	\
		./../outils/src/my_atoi.c	\
		./../outils/src/my_str_is.c	\
		./../outils/src/my_str.c	\
		./../outils/src/my_strdup.c	\
		./docs/init.c	\
		./docs/map_imperfect.c	\
		./docs/map_perfect.c	\
		./docs/output_map.c

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
	@$(RM) *.o
	@$(RM) src/*.o

re: 	fclean all

fclean: clean
	@echo -e $(BLUE) "[*** ALL CLEAN ***]"

########################
#####.PHONY#############
########################

.PHONY: all clean fclean re
	