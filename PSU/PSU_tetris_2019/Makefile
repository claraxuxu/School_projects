##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## tetris
##

SRC	=	./src/main.c			\
		./src/my_put.c			\
		./src/my_strlen.c		\
		./src/my_getnbr.c		\
		./src/my_atoi.c			\
		./src/my_str_is.c		\
		./src/my_strnuntil_cpy.c	\
		./src/my_strdup.c		\
		./src/my_str.c			\
		./src/my_printf.c		\
		./src/my_memset.c 		\
		./src/concat.c 			\
		./src/lib/situ_gene.c		\
		./src/lib/my_pow.c		\
		./src/lib/get_binary.c		\
		./src/lib/res_dif_int.c

SRC_CTX = 	./docs/context/extract_size.c \
			./docs/context/help.c 		\
			./docs/context/instance_str.c \
			./docs/context/manage_params.c \
			./docs/context/check_pattern_line_cmd.c \
			./docs/context/get_optarg.c

SRC_DBG =	./docs/debug/check.c 		\
			./docs/debug/display.c 		\
			./docs/debug/debug.c 		\
			./docs/debug/get_filepath_info.c \
			./docs/debug/get_tetri_name.c 	\
			./docs/debug/num_tetrimi.c 		\
			./docs/debug/sort.c

SRC_GRL = 	./docs/general/arrays.c 		\
			./docs/general/find_char.c 	\
			./docs/general/linked_lists_tools.c \
			./docs/general/read_file.c \
			./docs/general/split_str.c \
			./docs/general/counter_functions.c \
			./docs/general/strcpy_until.c

SRC_GAME =	./docs/game/prepare_game.c \
			./docs/game/display_interface.c	\
			./docs/game/clear_interface.c	\
			./docs/game/game_loop.c	\
			./docs/game/check_moves_hability.c	\
			./docs/game/handle_event.c	\
			./docs/game/level_upgrade.c	\
			./docs/game/tetrimino_moves.c \
			./docs/game/get_tetri.c \
			./docs/game/handle_game_event.c

NAME	=	tetris

OBJ		=	$(wildcard *.o)

CC		=	gcc

LDFLAGS	=	-g3

SOURCE	=	$(SRC) $(SRC_CTX) $(SRC_DBG) $(SRC_GRL) $(SRC_GAME)

all:	$(NAME)

$(NAME):
	$(CC) -c -lncurses $(LDFLAGS)  $(SOURCE) -Iinclude
	$(CC) $(LDFLAGS) -lncurses -o $(NAME) *.o
	mkdir objects
	mv *.o objects

clean:
	rm -rf objects
	rm -f *.o
	rm -f src/*.o

re: 	fclean all

fclean: clean
	rm -f $(NAME)
