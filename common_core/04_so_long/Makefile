# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 14:21:27 by Manny             #+#    #+#              #
#    Updated: 2022/11/30 21:13:34 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
#NAME_BONUS = so_long_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER) -I$(HEADER_GNL)
MLX = -L mlx -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

HEADER = so_long.h
HEADER_GNL = gnl/get_next_line.h

SRC_M = src/mandatory/image.c \
		src/mandatory/moves.c \
		src/mandatory/so_long.c
#SRC_B = src/bonus/enemy_bonus.c \
#		src/bonus/image_bonus.c \
#		src/bonus/moves_bonus.c \
#		src/bonus/so_long_bonus.c
SRC = src/actions.c \
		src/display_error.c \
		src/map_check.c \
		src/map_init.c
SRC_UTILS = src/utils/ft_itoa.c \
			src/utils/ft_putnbr_fd.c \
			src/utils/ft_putstr_fd.c \
			src/utils/ft_strcpy.c \
			src/utils/ft_strlen.c
SRC_GNL = gnl/get_next_line.c \
			gnl/get_next_line_utils.c

SRC_M += $(SRC)
SRC_M += $(SRC_UTILS)
SRC_M += $(SRC_GNL)
OBJ_M = $(SRC_M:.c=.o)

#SRC_B += $(SRC)
#SRC_B += $(SRC_UTILS)
#SRC_B += $(SRC_GNL)
#OBJ_B = $(SRC_B:.c=.o)
all: $(NAME)

$(NAME): $(OBJ_M) $(HEADER) $(HEADER_GNL)
	@make -s -C mlx
	$(CC) $(CFLAGS) $(MLX) $(OBJ_MANDATORY) -o $(NAME)
	@echo "\n\e[32m---- (っ▀¯▀)つ so_long is ready to play! ----\e[0m\n"

#bonus: $(NAME_BONUS)

#$(NAME_BONUS): $(OBJ_B) $(HEADER) $(HEADER_GNL)
#	@make -s -C mlx
#	$(CC) $(CFLAGS) $(MLX) $(OBJ_BONUS) -o $(NAME_BONUS)
#	@echo "\n\e[32m---- (っ▀¯▀)つ so_long_bonus is ready to play! ----\e[0m\n"

%.o: %.c $(HEADER) $(HEADER_GNL)
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	@make clean -s -C mlx
	$(RM) $(OBJ_M) $(OBJ_B)
	@echo "\n\e[31m---- (╯°□°)╯︵ ┻━┻ so_long is clean! ----\e[0m\n"

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	@echo "\n\e[31m---- (╯°□°）╯︵ ┻━┻ so_long is gone! ----\e[0m\n"

re: fclean all

#re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus