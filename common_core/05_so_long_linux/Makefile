# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 14:21:27 by Manny             #+#    #+#              #
#    Updated: 2023/07/17 05:48:20 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** EXECUTABLE ***** #
NAME = so_long
NAME_B = so_long_bonus

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
CFLAGS = -Wall -Wextra -Werror -I /$(INC) -I /$(GNL)
RM = rm -rf

# ***** MLX ************ #
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	MLX = -Lmlx -lmlx -Imlx -lXext -lX11 -lm -lz
else
	MLX = -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit
endif

# ***** INCLUDES ********* #
INC = so_long.h
GNL = gnl/get_next_line.h

# ***** SOURCES ******** #
SRC = src/actions.c \
		src/display_error.c \
		src/map_check.c \
		src/map_init.c \
		src/path_check.c

SRC_M = src/mandatory/image.c \
		src/mandatory/moves.c \
		src/mandatory/so_long.c

SRC_B = src/bonus/enemy_bonus.c \
		src/bonus/image_bonus.c \
		src/bonus/moves_bonus.c \
		src/bonus/so_long_bonus.c

SRC_UTILS = src/utils/ft_itoa.c \
			src/utils/ft_putnbr_fd.c \
			src/utils/ft_putstr_fd.c \
			src/utils/ft_strcpy.c \
			src/utils/ft_strlcpy.c \
			src/utils/ft_strdup.c \
			src/utils/ft_strlen.c
			
SRC_GNL = gnl/get_next_line.c \
			gnl/get_next_line_utils.c

# ***** OBJECTS ******** #
SRC_M += $(SRC)
SRC_M += $(SRC_UTILS)
SRC_M += $(SRC_GNL)
OBJ_M = $(SRC_M:.c=.o)

SRC_B += $(SRC)
SRC_B += $(SRC_UTILS)
SRC_B += $(SRC_GNL)
OBJ_B = $(SRC_B:.c=.o)

# ***** RULES ********** #
all: $(NAME)

$(NAME): $(OBJ_M) $(INC) $(GNL)
	@make -sC mlx
	@echo "\n$(BLUE) $(CC) $(CFLAGS) $(OBJ_M) $(MLX) -o $@ $(NC)"
	@$(CC) $(CFLAGS) $(OBJ_M) $(MLX) -o $@
	@echo "\n$(GREEN)---- (っ▀¯▀)つ $(NAME) is ready to play! ----$(NC)"

bonus: $(NAME_B)

$(NAME_B): $(OBJ_B) $(INC) $(GNL)
	@make -sC mlx
	@echo "\n$(BLUE) $(CC) $(CFLAGS) $(OBJ_B) $(MLX) -o $@ $(NC)"
	@$(CC) $(CFLAGS) $(OBJ_B) $(MLX) -o $@
	@echo "\n$(GREEN)---- (っ▀¯▀)つ $(NAME) bonus is ready to play! ----$(NC)\n"

%.o: %.c $(INC) $(INC_GNL)
	@echo "$(MAGENTA) $(CC) $(CFLAGS) -I/$(INC) -c $< -o $@ $(NC)"
	@$(CC) $(CFLAGS) -I/$(INC) -c $< -o $@

clean:
	$(RM) $(OBJ_M) $(OBJ_B)
	@make clean -sC mlx
	@echo "\n$(RED)---- ᕦ(ò_óˇ)ᕤ $(NAME) is clean! ----$(NC)\n"

fclean: clean
	$(RM) $(NAME) $(NAME_B)
	@echo "\n$(RED)---- (╯°□°）╯︵ ┻━┻ $(NAME) is gone! ----$(NC)\n"

re: fclean all

re_bonus: fclean bonus

# ***** MEMORY LEAKS *** #
mem1:
	valgrind --leak-check=summary ./$(NAME)
mem2:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
mem3:
	valgrind -s ./$(NAME)

.PHONY: all clean fclean re bonus re_bonus mem1 mem2 mem3