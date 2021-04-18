##
## EPITECH PROJECT, 2019
## CPE_dante_2019
## File description:
## Makefile
##

########################
#####VARIABLES##########
########################

GENERATOR	=	generator/
SOLVER		= 	solver/
CC			=	@make
CFLAGS		=  	-C

BLUE  	= 	"\e[34;1m"

########################
#####COMPILATION########
########################

all:
	@$(CC) $(CFLAGS) $(GENERATOR)
	@$(CC) $(CFLAGS) $(SOLVER)

clean:
	@$(CC) $(CFLAGS) $(GENERATOR) clean
	@$(CC) $(CFLAGS) $(SOLVER) clean

fclean:	clean
	@echo -e $(BLUE) "[*** ALL CLEAN ***]"

re:	fclean all

########################
#####.PHONY#############
########################

.PHONY:	all clean fclean re