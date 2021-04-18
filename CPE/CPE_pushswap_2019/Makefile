##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_sokoban
##

########################
#####VARIABLES##########
########################

NAME	=	push_swap

CC		=	@gcc
CFLAGS	=   -Wall -Wextra -g3 -Ofast

RED  	=  	"\e[31;1m"
GREEN 	= 	"\e[32;1m"
BLUE  	= 	"\e[34;1m"

########################
####FILES PATH##########
########################

SRC	=	./pushswap.c	\
		./src/isnum.c	\
		./src/my_putchar.c	\
		./src/my_putstr.c	\
		./src/my_strlen.c	\
		./src/sa_sb_sc.c	\
		./src/ra_rb_rr.c	\
		./src/rra_rrb_rrr.c	\
		./src/pa_pb.c	\
		./src/check_la.c	\
		./src/check_lb.c

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

re: 	fclean all

fclean: clean
	@echo -e $(BLUE) "[*** ALL CLEAN ***]"

########################
#####.PHONY#############
########################

.PHONY: all clean fclean re