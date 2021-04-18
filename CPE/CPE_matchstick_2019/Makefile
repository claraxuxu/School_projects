##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_matchstick
##

########################
#####VARIABLES##########
########################

NAME	=	matchstick
CC		=	gcc
RED  	=  	"\e[31;1m"
GREEN 	= 	"\e[32;1m"
BLUE  	= 	"\e[34;1m"

########################
####FILES PATH##########
########################

SRC	=	./match_stick.c	\
		./src/my_putchar.c	\
		./src/my_putstr.c	\
		./src/my_put_nbr.c	\
		./src/my_strlen.c	\
		./src/map.c	\
		./src/change_map.c	\
		./src/my_getnbr.c	\
		./src/get_next_line.c	\
		./src/get_answer.c	\
		./src/my_strncpy.c	\
		./src/my_str_isnum.c	\
		./src/my_printf.c	\
		./src/play.c	\
		./src/check_line.c	\
		./src/check_num.c	\
		./src/crand.c	\
		./src/play_bot.c	\
		./lib/situ_gene.c	\
		./lib/my_pow.c		\
		./lib/get_float.c	\
		./lib/get_octal.c	\
		./lib/get_binary.c	\
		./lib/res_dif_int.c

RM		= 	@rm -rf

OBJS	=	$(SRC:.c=.o)

########################
#####COMPILATION########
########################

all:	$(NAME)

$(NAME):
	@$(CC) -c -g3 $(SRC) -I./include
	@$(CC) -g3 -o $(NAME) *.o
	@mkdir objects
	@mv *.o objects
	@echo -e $(GREEN) "[*** COMPILATION SUCCESSFUL ***]"

clean:
	@$(RM) objects/
	@$(RM) *.o
	@$(RM) src/*.o

re: 	fclean all

fclean: clean
	@$(RM) $(NAME)
	@echo -e $(BLUE) "[*** CLEAN ***]"

########################
#####.PHONY#############
########################

.PHONY: all clean fclean re