CC = gcc

CFLAGS =  -Wall -Wextra -Werror

MLX = ./includes/libmlx.a

NAME = cub3D

SRC = main.c \
		./utils/display_utils.c \
		./utils/check_arg.c \
		./utils/lib_utils.c \
		./utils/ft_split.c \
		./utils/first_part_utils.c \
		./utils/first_part_utils2.c \
		./utils/first_part_utils3.c \
		./utils/first_part_utils4.c \
		./utils/second_part_utils.c \
		./utils/second_part_utils2.c \
		./utils/second_part_utils3.c \
		./utils/second_part_utils4.c \
		./utils/struct_init.c \
		./GNL/get_next_line.c \
		./GNL/get_next_line_utils.c \
		./parsing/parsing.c \
		./parsing/parsing_first.c \
		./parsing/parsing_two.c \
		./parsing/take_the_map.c \
		./srcs/draw_map.c \
		./srcs/draw_utils.c \
		./srcs/in_game.c \
		./srcs/in_game_utils.c \
		./srcs/move.c \
		./srcs/move_utils.c \
		./srcs/find_walls.c \
		./srcs/find_walls_utils.c \
		

OBJ = $(SRC:.c=.o)

RM = rm -f

%.o : %.c
		$(CC) -o $@ -c $< $(CFLAGS)

LIBS = $(MLX) -framework OpenGL -framework AppKit -lm

$(NAME) 	:	$(MLX) $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIBS)

all : $(NAME)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

