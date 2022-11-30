# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 14:21:27 by Manny             #+#    #+#              #
#    Updated: 2022/11/30 19:26:19 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
#NAME_BONUS = so_long_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
MLX = -lmlx -lXext -lX11 -lm -lz
RM = rm -rf

INCLUDES = -I ./include/ -I ./lib/gnl

SRC = src/actions.c src/display_error.c src/image.c src/map.check.c\
		src/map_init.c src/moves.c src/so_long.c

SRC_GNL = ./lib/gnl/*.c
UTILS = ./lib/*c

all: $(NAME)

$(NAME): $(SRC) $(SRC_GNL) $(UTILS)
	$(MAKE) -s -C mlx
	$(CC) $(CFLAGS) $(INCLUDES) $(MLX) $^ -o $@
	@echo "\n\e[32m---- (っ▀¯▀)つ so_long is ready to play! ----\e[0m\n"

#bonus: $(NAME_BONUS)

#$(NAME_BONUS): $(OBJ_M) $(OBJ) $(OBJ_UTILS) $(OBJ_GNL) $(OBJ_BONUS)
#	$(MAKE) -C mlx
#	$(CC) $(CFLAGS) $(HEADER) $(HEADER_GNL) $(MLX) $^ -o $@
#	@echo "\n\e[32m---- (っ▀¯▀)つ so_long_bonus is ready to play! ----\e[0m\n"

%.o: %.c 
	$(CC) $(CFLAGS) $(SRC) $(UTILS) -c $< -o $@

clean:
	$(RM) $(OBJ_M) $(OBJ) $(OBJ_UTILS) $(OBJ_GNL)
	$(MAKE) clean -C mlx
	@echo "\n\e[31m---- (╯°□°)╯︵ ┻━┻ so_long is clean! ----\e[0m\n"

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	@echo "\n\e[31m---- (╯°□°）╯︵ ┻━┻ so_long is gone! ----\e[0m\n"

re: fclean all

#re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus 
