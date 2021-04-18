##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## infinadd
##

MAIN     	=	src/main.c					\

ERROR		=	src/error/error.c			\
			src/error/handl_error.c			\
			src/error/tunnel.c

CONVERSION	=	src/conversion/conversion.c	\
				src/conversion/checkings.c	\

ALGORITHM	=	src/algorithm/algorithm.c	\
				src/algorithm/math_fonc.c	\
				src/algorithm/init_distance.c	\

CC			=	@gcc
CFLAGS		=   -Iinclude -W -Wall -Wextra -g -g3

NAME		=	lemin

UNITS		=	Units_Test

UNIT_FILE	=	Units/units_test.c

CRITERION	=	--coverage -lcriterion
RM		= 	@rm -rf

all:
	@make -C lib
	@$(CC) $(CFLAGS) $(MAIN) $(ERROR) $(CONVERSION) $(ALGORITHM) -o $(NAME) -L. -lmy

clean:
	@$(RM) $(OBJ)
	@$(RM) $(NAME)
	@$(RM) $(BRUH)
	@make -C lib clean

fclean: clean
	@echo -e $(BLUE) "[*** ALL CLEAN ***]"

re:     fclean all

tests_run:
	@make -C lib/my
	@$(CC) -o $(UNITS) $(UNIT_FILE) $(ERROR) $(GAME) $(ADDS) $(CRITERION) -I./include -lmy -L.
	./$(UNITS)

t:	tests_run

t_clean:	fclean
	@$(RM) *.gc*
	@$(RM) $(UNITS)

rt: t_clean t

g:
	gcovr --exclude $(UNIT_FILE)
