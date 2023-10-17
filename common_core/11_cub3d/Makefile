# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 19:52:44 by Manny             #+#    #+#              #
#    Updated: 2023/10/17 16:47:16 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** EXECUTABLE ***** #
NAME = cub3D

# ***** BONUS MODE ***** #
BONUS = 0

# ***** COLORS ********* #
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
MAGENTA	= \033[0;35m
CYAN	= \033[0;36m
BOLD	= \033[1m
ITALIC	= \033[3m
ULINE	= \033[4m
BLINK	= \033[5m
NC		= \033[0m

# ***** COMPILATION **** #
CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# ***** MLX ************ #
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	MLX = -Lmlx -lmlx -Imlx -lXext -lX11 -lm -lz
else
	MLX = -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit
endif

# ***** INCLUDES ******* #
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	INC = -I ./inc/ -I ./libft/ -I ./minilibx-linux/
else
	INC = -I ./inc/ -I ./libft/ -I ./minilibx_opengl/
endif

# ***** SOURCES ******** #
SRC_DIR = ./src/
SRC = 	error.c \
		main.c \
		exit/exit.c \
		exit/free_data.c \
		init/init_data.c \
		init/init_mlx.c \
		init/init_textures.c \
		movements/input_handler.c \
		movements/player_dir.c \
		movements/player_move.c \
		movements/player_pos.c \
		movements/player_rotate.c \
		parsing/check_args.c \
		parsing/check_map_borders.c \
		parsing/check_map.c \
		parsing/check_textures.c \
		parsing/create_map.c \
		parsing/fill_color_textures.c \
		parsing/get_file_data.c \
		parsing/parse_data.c \
		parsing/parsing_utils.c \
		rendering/images_utils.c \
		rendering/raycasting.c \
		rendering/render.c \
		rendering/textures.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

# ***** OBJECTS ******** #
OBJ_DIR = ./obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

# ***** RULES ********** #
all: $(OBJ_DIR) $(NAME)

 $(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/exit
	@mkdir -p $(OBJ_DIR)/init
	@mkdir -p $(OBJ_DIR)/movements
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/rendering

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(MAGENTA) $(CC) $(CFLAGS) $(INC) -c $< -o $@ $(NC)"
	@$(CC) $(CFLAGS) $(INC) -DBONUS=$(BONUS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "\n$(BLUE) $(CC) $(CFLAGS) $(OBJS) $(MLX) -o $@ $(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -DBONUS=$(BONUS) -o $@
	@echo "\n$(GREEN)---- (っ▀¯▀)つ $(NAME) is ready! ----$(NC)\n"

$(LIBFT):
	@make -sC ./libft/

bonus:
	make all BONUS=1

clean:
	@$(RM) $(OBJ_DIR)
	@echo "\n$(YELLOW) $(RM) $(OBJ_DIR) $(NC)"
	@echo "\n$(RED)---- ᕦ(ò_óˇ)ᕤ $(NAME) is clean! ----$(NC)\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "\n$(YELLOW) $(RM) $(NAME) $(NC)"
	@echo "\n$(RED)---- (╯°□°）╯︵ ┻━┻ $(NAME) is gone! ----$(NC)\n"

re: fclean all

# ***** MEMORY LEAKS **** #
mem1:
	valgrind --leak-check=summary ./$(NAME)
mem2:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)
mem3:
	valgrind -s ./$(NAME)

.PHONY : all clean fclean re mem1 mem2 mem3