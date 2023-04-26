# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 18:47:27 by Manny             #+#    #+#              #
#    Updated: 2023/04/26 18:49:07 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishel

CC = gcc -g3 -pthread #-fsanitize=thread
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INC = -I ./

SRC_PATH = src/
SRC = [...]

SRCS	= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "\n\033[32m---- (っ▀¯▀)つ minishell is ready! ----\033[0m\n"

clean:
	$(RM) $(OBJ_PATH)
	@echo "\n\033[31m---- (╯°□°)╯︵ ┻━┻ minishell is clean! ----\033[0m\n"

fclean: clean
	$(RM) $(NAME)
	@echo "\n\033[31m---- (╯°□°）╯︵ ┻━┻ minishell is gone! ----\033[0m\n"

re: fclean all

.PHONY: all clean fclean re