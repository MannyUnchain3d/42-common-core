# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 13:33:09 by Manny             #+#    #+#              #
#    Updated: 2023/07/13 17:55:07 by etetopat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** EXECUTABLE ***** #
NAME = pipex

# ***** COMPILATION **** #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = -rm -rf

# ***** SOURCES ******** #
SRC_DIR = src
SRC = pipex.c utils.c
SRC_B = pipex_bonus.c utils.c utils_bonus.c

# ***** OBJECTS ******** #
OBJ_DIR = obj
OBJ = $(SRC:%.c=$(SRC_DIR)/$(OBJ_DIR)/%.o)
OBJ_B = $(SRC_B:%.c=$(SRC_DIR)/$(OBJ_DIR)/%.o)

# ***** HEADER ********* #
HEADER = -I inc

# ***** LIBFT ********** #
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
lIBFTFLAGS = -L$(LIBFT_DIR) -lft

# ***** OBJECTS ******** #
$(SRC_DIR)/$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(SRC_DIR)/$(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

# ***** RULES ********** #
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(lIBFTFLAGS) -o $(NAME)
	@echo "\n\033[32m---- (っ▀¯▀)つ $(NAME) is compiled! ----\033[0m\n"

bonus: $(LIBFT) $(OBJ) $(OBJ_B)
	$(CC) $(OBJ_B) $(lIBFTFLAGS) -o $(NAME)
	@echo "\n\033[32m---- (っ▀¯▀)つ $(NAME) bonus is compiled! ----\033[0m\n"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(SRC_DIR)/$(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)
	@echo "\n\033[31m---- ᕦ(ò_óˇ)ᕤ full cleaning done! ----\033[0m\n"

re: fclean all

re_bonus: fclean bonus

# ***** MEMORY LEAKS *** #
mem1:
	valgrind --leak-check=summary ./$(NAME)
mem2:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
mem3:
	valgrind -s ./$(NAME)

.PHONY : all clean fclean re bonus re_bonus mem1 mem2 mem3