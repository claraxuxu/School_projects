##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## task01
##

########################
#####VARIABLES##########
########################

NAME	=	libmy.a
FILE	=	my.h
AR		=	ar rc
OBJ	=	$(SRC:.c=.o)

RED  	=  	"\e[31;1m"
GREEN 	= 	"\e[32;1m"
BLUE  	= 	"\e[34;1m"

########################
####FILES PATH##########
########################

SRC	=	my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_find_prime_sup.c			\
		my_getnbr.c					\
		my_itoa.c					\
		my_isneg.c					\
		my_is_prime.c				\
		my_putchar.c				\
		my_put_nbr.c				\
		my_putstr.c					\
		my_revstr.c					\
		my_strcapitalize.c			\
		my_strcat.c					\
		my_strcmp.c					\
		my_strcpy.c					\
		my_str_isalpha.c			\
		my_str_isnum.c				\
		my_str_isprintable.c		\
		my_strlen.c					\
		my_strncat.c				\
		my_strncmp.c				\
		my_strncpy.c				\
		my_strstr.c					\
		my_swap.c					\
		my_putab.c					\
		my_str_tab.c				\
		my_str_retab.c				\
		my_sort_params.c			\

RM		= 	@rm -rf

########################
#####COMPILATION########
########################

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@mv $(NAME) ../
	@cp $(FILE) ../include/
	@mkdir objects/
	@mv *.o objects/
	@echo -e $(GREEN) "[*** COMPILATION NM SUCCEED ***]"

clean:
	@$(RM) $(OBJ)
	@$(RM) ../$(NAME)
	@$(RM) ../include/$(FILE)
	@$(RM) objects/

fclean: clean
	@echo -e $(BLUE) "[*** ALL CLEAN ***]"

re:	fclean all

########################
#####.PHONY#############
########################

.PHONY: all clean fclean re