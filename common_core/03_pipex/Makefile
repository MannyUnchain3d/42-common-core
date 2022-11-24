# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 13:33:09 by Manny             #+#    #+#              #
#    Updated: 2022/11/25 02:13:51 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END = \e[0m
BOLD = \e[1m
UNDER = \e[4m
REV = \e[7m
GREY = \e[30m
RED = \e[31m
GREEN = \e[32m
YELLOW = \e[33m
BLUE = \e[34m
PURPLE = \e[35m
CYAN = \e[36m
WHITE = \e[37m

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = -rm -rf

SRC_DIR = src
SRC = pipex.c utils.c
SRC_B = pipex_bonus.c utils.c utils_bonus.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(SRC_DIR)/$(OBJ_DIR)/%.o)
OBJ_B = $(SRC_B:%.c=$(SRC_DIR)/$(OBJ_DIR)/%.o)

HEADER = -Iinclude

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
lIBFTFLAGS = -L$(LIBFT_DIR) -lft

$(SRC_DIR)/$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(SRC_DIR)/$(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(lIBFTFLAGS) -o $(NAME)
	@echo "\n$(GREEN)---- (っ▀¯▀)つ pipex is compiled! ----$(END)\n"

bonus: $(LIBFT) $(OBJ) $(OBJ_B)
	$(CC) $(OBJ_B) $(lIBFTFLAGS) -o $(NAME_B)
	@echo "\n$(GREEN)---- (っ▀¯▀)つ pipex bonus is compiled! ----$(END)\n"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(SRC_DIR)/$(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)
	@echo "\n$(RED)---- ᕦ(ò_óˇ)ᕤ full cleaning done! ----$(END)\n"

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus 