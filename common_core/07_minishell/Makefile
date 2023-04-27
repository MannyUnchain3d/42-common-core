# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 18:47:27 by Manny             #+#    #+#              #
#    Updated: 2023/04/27 00:32:05 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

CC = gcc -g3 #-fsanitize=address
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INC = -I ./ -I $(LIBFT_PATH)

LIBFT_PATH = ./libft/
LIBFT = ./libft/libft.a

SRC_PATH = ./src/
SRC = main.c \
		builtins/[...].c \
		...
		...
		...
		executor/[...].c \
		...
		...
		...


SRCS	= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = ./obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(OBJ_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(OBJ_PATH)/builtins
	mkdir -p $(OBJ_PATH)/executor
	mkdir -p $(OBJ_PATH)/expander
	mkdir -p $(OBJ_PATH)/env
	mkdir -p $(OBJ_PATH)/lexer
	mkdir -p $(OBJ_PATH)/parser
	mkdir -p $(OBJ_PATH)/redirections
	mkdir -p $(OBJ_PATH)/signals
	mkdir -p $(OBJ_PATH)/utils

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC) $(LIBFT) -l readline
	@echo "\n\033[32m---- (っ▀¯▀)つ minishell is ready! ----\033[0m\n"

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJ_PATH)
	@echo "\n\033[31m---- (╯°□°)╯︵ ┻━┻ minishell is clean! ----\033[0m\n"

fclean: clean
	$(RM) $(NAME)
	@echo "\n\033[31m---- (╯°□°）╯︵ ┻━┻ minishell is gone! ----\033[0m\n"

re: fclean all

.PHONY: all clean fclean re