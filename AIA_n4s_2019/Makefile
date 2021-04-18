##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

########################
#####VARIABLES##########
########################

NAME	= ai

LIBPATH = ./lib/my/.
CC		= @gcc
RM		= @rm -rf
CFLAGS 	= -L. -lguillem -I./includes/ \
		  -g3


########################
####FILES PATH##########
########################

SRC		 = ./sources/main.c

API 	= ./sources/api_answer/get_answer.c \
		  ./sources/api_answer/get_answer_type.c \
		  ./sources/api_answer/get_format_types.c \
		  ./sources/api_answer/extract_data.c \
		  ./sources/api_answer/init_data.c \
		  ./sources/api_answer/log_file_handler.c

LOOP  	= ./sources/loop_handling/check_if_end_loop.c \
		  ./sources/loop_handling/get_status.c \
		  ./sources/loop_handling/loop.c

QUEST  	= ./sources/api_quest/get_question.c \
		  ./sources/api_quest/forward_or_backward.c \
		  ./sources/api_quest/compute_floats.c

TEST_SRC = ./tests/tests_gnl.c \
		   ./tests/tests_lib2.c \
		   ./tests/tests_lib.c \
		   ./tests/tests_api_answer.c \
		   ./tests/tests_answer_type.c


########################
#####COMPILATION########
########################

all: $(NAME)

$(NAME):
	@make --no-print-directory -C $(LIBPATH)
	@$(CC) -c $(SRC) $(API) $(LOOP) $(QUEST) $(CFLAGS)
	@$(CC) *.o -o $(NAME) $(CFLAGS)
	@mkdir -p objects
	@mv *.o objects
	@$(CC) objects/*.o -o $(NAME) $(CFLAGS)
	@echo "[*** COMPILATION SUCCESSFUL ***]"

clean:
	@make clean --no-print-directory -C $(LIBPATH)
	@$(RM) objects

fclean: clean
	@make fclean --no-print-directory -C $(LIBPATH)
	@$(RM) $(NAME)
	@echo "[*** CLEAN ***]"

re: fclean all

########################
#####UNIT TESTS#########
########################

tests_run:
	@make --no-print-directory -C $(LIBPATH)
	@$(CC) -c $(TEST_SRC) $(API) $(QUEST) $(LOOP) --coverage -g3 -I./includes -lguillem
	@$(CC) -o unit_tests *.o -lcriterion --coverage -I./includes -L. -lguillem
	@mkdir -p objects
	@mv *.o objects
	@./unit_tests > /dev/null
	@echo "[*** TESTS OVER ***]"

tests_run_clean: tests_run
	@gcovr --exclude tests/
	@make fclean --no-print-directory -C $(LIBPATH)
	@$(RM) unit_tests
	@$(RM) *.gc* unit_tests
	@$(RM) $(NAME)
	@$(RM) objects
	@echo "[*** CLEAN SUCCESSFUL ***]"


########################
#####.PHONY#############
########################

.PHONY: all clean fclean re tests_run tests_run_clean
